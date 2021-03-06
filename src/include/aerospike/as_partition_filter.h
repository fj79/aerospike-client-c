/*
 * Copyright 2008-2020 Aerospike, Inc.
 *
 * Portions may be licensed to Aerospike, Inc. under one or more contributor
 * license agreements.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
#pragma once

#include <aerospike/as_std.h>
#include <aerospike/as_key.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * TYPES
 *****************************************************************************/

/**
 * Partition filter.
 */
typedef struct as_partition_filter_s {
	uint16_t begin;
	uint16_t count;
	as_digest digest;
} as_partition_filter;

/******************************************************************************
 * FUNCTIONS
 ******************************************************************************/

/**
 * Filter by partition id.
 *
 * @param pf			Partition filter.
 * @param part_id		Partition id (0 - 4095).
 */
static inline void
as_partition_filter_set_id(as_partition_filter* pf, uint32_t part_id)
{
	pf->begin = part_id;
	pf->count = 1;
	pf->digest.init = false;
}

/**
 * Return records after key's digest in partition containing the digest.
 * Note that digest order is not the same as user key order.
 *
 * @param pf			Partition filter.
 * @param digest		Return records after this key's digest.
 */
static inline void
as_partition_filter_set_after(as_partition_filter* pf, as_digest* digest)
{
	pf->begin = 0;
	pf->count = 1;
	pf->digest = *digest;
}

/**
 * Filter by partition range.
 *
 * @param pf			Partition filter.
 * @param begin			Start partition id (0 - 4095).
 * @param count			Number of partitions.
 */
static inline void
as_partition_filter_set_range(as_partition_filter* pf, uint32_t begin, uint32_t count)
{
	pf->begin = begin;
	pf->count = count;
	pf->digest.init = false;
}

#ifdef __cplusplus
} // end extern "C"
#endif
