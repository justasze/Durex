/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:53:27 by ndombre           #+#    #+#             */
/*   Updated: 2019/03/03 16:08:57 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static const uint64_t	g_k[] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538,
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe,
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f,
	0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4,
	0x76f988da831153b5, 0x983e5152ee66dfab,
	0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8,
	0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791,
	0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63,
	0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
	0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60,
	0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c,
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6,
	0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84,
	0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

static const uint64_t	g_init[] = {
	0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b,
	0xa54ff53a5f1d36f1,
	0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b,
	0x5be0cd19137e2179
};

static void				sha512_transform_init(uint64_t *data, uint64_t w[80])
{
	int			i;

	i = 0;
	while (i < 16)
	{
		w[i] = conv_bigendian_64(data[i]);
		i++;
	}
	i = 16;
	while (i < 80)
	{
		w[i] = w[i - 16]
			+ (ror_64(w[i - 15], 1)
					^ ror_64(w[i - 15], 8) ^ (w[i - 15] >> 7)) + w[i - 7]
			+ (ror_64(w[i - 2], 19)
					^ ror_64(w[i - 2], 61) ^ (w[i - 2] >> 6));
		i++;
	}
}

static void				sha512_transform_temp(uint64_t out[8], uint64_t data)
{
	uint64_t temp1;
	uint64_t temp2;

	temp1 = out[7]
		+ (ror_64(out[4], 14) ^ ror_64(out[4], 18) ^ ror_64(out[4], 41))
		+ ((out[4] & out[5]) ^ (~(out[4]) & out[6])) + data;
	temp2 = (ror_64(out[0], 28) ^ ror_64(out[0], 34) ^ ror_64(out[0], 39))
		+ ((out[0] & out[1]) ^ (out[0] & out[2]) ^ (out[1] & out[2]));
	out[7] = out[6];
	out[6] = out[5];
	out[5] = out[4];
	out[4] = out[3] + temp1;
	out[3] = out[2];
	out[2] = out[1];
	out[1] = out[0];
	out[0] = temp1 + temp2;
}

void					sha512_transform(uint64_t out[8], uint64_t *data)
{
	uint64_t	w[80];
	uint64_t	out_save[8];
	int			i;

	ft_memcpy(out_save, out, sizeof(uint64_t) * 8);
	sha512_transform_init(data, w);
	i = 0;
	while (i < 80)
	{
		sha512_transform_temp(out, g_k[i] + w[i]);
		i++;
	}
	out[0] += out_save[0];
	out[1] += out_save[1];
	out[2] += out_save[2];
	out[3] += out_save[3];
	out[4] += out_save[4];
	out[5] += out_save[5];
	out[6] += out_save[6];
	out[7] += out_save[7];
}

uint64_t				sha512_get_block(void *in, uint64_t size, uint8_t **out)
{
	uint64_t	new_len;

	new_len = size + 1;
	while (new_len % 1024 != 896)
		new_len++;
	new_len /= 8;
	if ((*out = ft_memalloc(new_len + 64 / 8 + 100)) == NULL)
		return (0);
	ft_memcpy(*out, in, size / 8 + (size % 8 != 0 ? 1 : 0));
	(*out)[size / 8 + (size % 8 != 0 ? 1 : 0)] &= 0b11111111 << (8 - size % 8);
	(*out)[size / 8 + (size % 8 != 0 ? 1 : 0)] |= 0b10000000 >> (size % 8);
	size = conv_bigendian_64(size);
	ft_memcpy((*out) + new_len + 8, &size, 8);
	return (new_len);
}

int						sha512(uint32_t out[16], void *in, uint64_t size)
{
	uint8_t		*msg;
	uint64_t	new_len;
	uint64_t	i;
	uint64_t	*hash;

	hash = (uint64_t*)out;
	ft_memcpy(hash, g_init, sizeof(g_init));
	if ((new_len = sha512_get_block(in, size, &msg)) == 0)
		return (1);
	i = 0;
	while (i < new_len)
	{
		sha512_transform(hash, (uint64_t*)(msg + i));
		i += 16 * sizeof(uint64_t);
	}
	free(msg);
	i = 0;
	while (i < 8)
	{
		hash[i] = conv_bigendian_64(hash[i]);
		i++;
	}
	return (0);
}
