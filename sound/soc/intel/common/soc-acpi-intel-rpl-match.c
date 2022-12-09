// SPDX-License-Identifier: GPL-2.0-only
/*
 * soc-apci-intel-rpl-match.c - tables and support for RPL ACPI enumeration.
 *
 * Copyright (c) 2022 Intel Corporation.
 */

#include <sound/soc-acpi.h>
#include <sound/soc-acpi-intel-match.h>

static const struct snd_soc_acpi_endpoint single_endpoint = {
	.num = 0,
	.aggregated = 0,
	.group_position = 0,
	.group_id = 0,
};

static const struct snd_soc_acpi_adr_device rt711_0_adr[] = {
	{
		.adr = 0x000020025D071100ull,
		.num_endpoints = 1,
		.endpoints = &single_endpoint,
		.name_prefix = "rt711"
	}
};

static const struct snd_soc_acpi_link_adr rpl_rvp[] = {
	{
		.mask = BIT(0),
		.num_adr = ARRAY_SIZE(rt711_0_adr),
		.adr_d = rt711_0_adr,
	},
	{}
};

struct snd_soc_acpi_mach snd_soc_acpi_intel_rpl_machines[] = {
	{},
};
EXPORT_SYMBOL_GPL(snd_soc_acpi_intel_rpl_machines);

/* this table is used when there is no I2S codec present */
struct snd_soc_acpi_mach snd_soc_acpi_intel_rpl_sdw_machines[] = {
	{
		.link_mask = 0x1, /* link0 required */
		.links = rpl_rvp,
		.drv_name = "sof_sdw",
		.sof_tplg_filename = "sof-rpl-rt711.tplg",
	},
	{},
};
EXPORT_SYMBOL_GPL(snd_soc_acpi_intel_rpl_sdw_machines);
