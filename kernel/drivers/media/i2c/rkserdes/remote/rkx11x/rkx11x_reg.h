/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2024 Rockchip Electronics Co. Ltd.
 *
 * Author: Zhang Yubing <yubing.zhang@rock-chips.com>
 */

#ifndef __RKX11X_REG_H__
#define __RKX11X_REG_H__

#include <linux/bits.h>

#define UPDATE(v, h, l)			(((v) << (l)) & GENMASK((h), (l)))
#define HIWORD_UPDATE(v, m, l)		(((v) << (l)) | (m << 16))
#define HIWORD_MASK(h, l)		(GENMASK(h, l) | GENMASK(h, l) << 16)

/************** RK11X SER TX ***************/
#define RKX11X_SER_CRU_BASE		0x00000000

#define RKX11X_SER_GRF_BASE		0x00010000

/* RK11X GRF Register */
#define SER_GRF_REG(x)			(RKX11X_SER_GRF_BASE + (x))

#define SER_GRF_GPIO0A_IOMUX_L		SER_GRF_REG(0x0000)
#define SER_GRF_GPIO0A_IOMUX_H		SER_GRF_REG(0x0004)
#define SER_GRF_GPIO0B_IOMUX_L		SER_GRF_REG(0x0008)
#define SER_GRF_GPIO0B_IOMUX_H		SER_GRF_REG(0x000c)
#define SER_GRF_GPIO0C_IOMUX_L		SER_GRF_REG(0x0010)
#define SER_GRF_GPIO0C_IOMUX_H		SER_GRF_REG(0x0014)
#define SER_GRF_GPIO0A_PULL_EN		SER_GRF_REG(0x0020)
#define SER_GRF_GPIO0B_PULL_EN		SER_GRF_REG(0x0024)
#define SER_GRF_GPIO0C_PULL_EN		SER_GRF_REG(0x0028)
#define SER_GRF_GPIO1A_IOMUX		SER_GRF_REG(0x0080)
#define SER_GRF_GPIO1B_IOMUX		SER_GRF_REG(0x0084)
#define SER_GRF_GPIO1C_IOMUX		SER_GRF_REG(0x0088)
#define SER_GRF_GPIO1A_PULL_CFG		SER_GRF_REG(0x0090)
#define SER_GRF_GPIO1B_PULL_CFG		SER_GRF_REG(0x0094)
#define SER_GRF_GPIO1C_PULL_CFG		SER_GRF_REG(0x0098)

enum {
	/* GPIO0A_IOMUX_H */
	GPIO0A7_SHIFT		= 6,
	GPIO0A7_MASK		= GENMASK(8, 6),
	GPIO0A7_GPIO		= 0,
	GPIO0A7_SPI_MISO_M,
	GPIO0A7_SPI_MISO_S,
	GPIO0A7_UART1_TX_M,
	GPIO0A7_UART1_TX_S,
	GPIO0A7_GPO_2,
	GPIO0A7_GPI_2,
	GPIO0A7_TP15,

	GPIO0A6_SHIFT		= 3,
	GPIO0A6_MASK		= GENMASK(5, 3),
	GPIO0A6_GPIO		= 0,
	GPIO0A6_SPI_MOSI_M,
	GPIO0A6_SPI_MOSI_S,
	GPIO0A6_UART0_RX_M,
	GPIO0A6_UART0_RX_S,
	GPIO0A6_GPO_1,
	GPIO0A6_GPI_1,
	GPIO0A6_I2C_DEBUG_SDA,

	GPIO0A5_SHIFT		= 0,
	GPIO0A5_MASK		= GENMASK(2, 0),
	GPIO0A5_GPIO		= 0,
	GPIO0A5_SPI_CLK_M,
	GPIO0A5_SPI_CLK_S,
	GPIO0A5_UART0_TX_M,
	GPIO0A5_UART0_TX_S,
	GPIO0A5_GPO_0,
	GPIO0A5_GPI_0,
	GPIO0A5_I2C_DEBUG_SCL,

	/* GPIO0A_IOMUX_L */
	GPIO0A4_SHIFT		= 12,
	GPIO0A4_MASK		= GENMASK(14, 12),
	GPIO0A4_GPIO		= 0,
	GPIO0A4_INT_RX,
	GPIO0A4_INT_TX,

	GPIO0A3_SHIFT		= 9,
	GPIO0A3_MASK		= GENMASK(11, 9),
	GPIO0A3_GPIO		= 0,
	GPIO0A3_I2C0_ADDRSEL,

	GPIO0A0_SHIFT		= 0,
	GPIO0A0_MASK		= GENMASK(2, 0),
	GPIO0A0_GPIO		= 0,
	GPIO0A0_LINK_TYPE,

	/* GPIO0B_IOMUX_H */
	GPIO0B7_SHIFT		= 6,
	GPIO0B7_MASK		= GENMASK(8, 6),
	GPIO0B7_GPIO		= 0,
	GPIO0B7_I2S_MCLK,
	GPIO0B7_TEST_CLK_OUT,
	GPIO0B7_MIPI_MCLK0,
	GPIO0B7_TP6,

	GPIO0B6_SHIFT		= 5,
	GPIO0B6_MASK		= GENMASK(5, 3),
	GPIO0B6_GPIO		= 0,
	GPIO0B6_I2S_SDI3,
	GPIO0B6_I2S_SDO0,
	GPIO0B6_TP5,

	GPIO0B5_SHIFT		= 2,
	GPIO0B5_MASK		= GENMASK(2, 0),
	GPIO0B5_GPIO		= 0,
	GPIO0B5_I2S_SDI2,
	GPIO0B5_GPI_6,
	GPIO0B5_GPO_6,
	GPIO0B5_I2C1_SDA_M,
	GPIO0B5_I2C1_SDA_S,
	GPIO0B5_TP4,

	/* GPIO0B_IOMUX_L */
	GPIO0B4_SHIFT		= 12,
	GPIO0B4_MASK		= GENMASK(14, 12),
	GPIO0B4_GPIO		= 0,
	GPIO0B4_I2S_SDI1,
	GPIO0B4_GPI_5,
	GPIO0B4_GPO_5,
	GPIO0B4_I2C1_SCL_M,
	GPIO0B4_I2C1_SCL_S,
	GPIO0B4_TP3,

	GPIO0B3_SHIFT		= 11,
	GPIO0B3_MASK		= GENMASK(11, 9),
	GPIO0B3_GPIO		= 0,
	GPIO0B3_I2S_SDI0,
	GPIO0B3_GPI_4,
	GPIO0B3_GPO_4,
	GPIO0B3_TP2,

	GPIO0B2_SHIFT		= 6,
	GPIO0B2_MASK		= GENMASK(8, 6),
	GPIO0B2_GPIO		= 0,
	GPIO0B2_I2S_LRCK_M,
	GPIO0B2_I2S_LRCK_S,
	GPIO0B2_TP1,

	GPIO0B1_SHIFT		= 3,
	GPIO0B1_MASK		= GENMASK(5, 3),
	GPIO0B1_GPIO		= 0,
	GPIO0B1_I2S_SCLK_M,
	GPIO0B1_I2S_SCLK_S,
	GPIO0B1_TP0,

	GPIO0B0_SHIFT		= 0,
	GPIO0B0_MASK		= GENMASK(2, 0),
	GPIO0B0_GPIO		= 0,
	GPIO0B0_SPI_CSN_M,
	GPIO0B0_SPI_CSN_S,
	GPIO0B0_UART1_RX_M,
	GPIO0B0_UART1_RX_S,
	GPIO0B0_GPO_3,
	GPIO0B0_GPI_3,
	GPIO0B0_TP16,

	/* GPIO0C_IOMUX_H */
	GPIO0C7_SHIFT		= 6,
	GPIO0C7_MASK		= GENMASK(8, 6),
	GPIO0C7_GPIO		= 0,
	GPIO0C7_LCDC_D3,
	GPIO0C7_CIF_D3,
	GPIO0C7_TP14,

	GPIO0C6_SHIFT		= 3,
	GPIO0C6_MASK		= GENMASK(5, 3),
	GPIO0C6_GPIO		= 0,
	GPIO0C6_LCDC_D2,
	GPIO0C6_CIF_D2,
	GPIO0C6_TP13,

	GPIO0C5_SHIFT		= 0,
	GPIO0C5_MASK		= GENMASK(2, 0),
	GPIO0C5_GPIO		= 0,
	GPIO0C5_LCDC_D1,
	GPIO0C5_CIF_D1,
	GPIO0C5_TP12,

	/* GPIO0C_IOMUX_L */
	GPIO0C4_SHIFT		= 12,
	GPIO0C4_MASK		= GENMASK(14, 12),
	GPIO0C4_GPIO		= 0,
	GPIO0C4_LCDC_D0,
	GPIO0C4_CIF_D0,
	GPIO0C4_TP11,

	GPIO0C3_SHIFT		= 9,
	GPIO0C3_MASK		= GENMASK(11, 9),
	GPIO0C3_GPIO		= 0,
	GPIO0C3_LCDC_DEN,
	GPIO0C3_CIF_CLK_OUT,
	GPIO0C3_MIPI_CLK1,
	GPIO0C3_TP10,

	GPIO0C2_SHIFT		= 6,
	GPIO0C2_MASK		= GENMASK(8, 6),
	GPIO0C2_GPIO		= 0,
	GPIO0C2_LCDC_HSYNC,
	GPIO0C2_CIF_HSYNC,
	GPIO0C2_TP9,

	GPIO0C1_SHIFT		= 3,
	GPIO0C1_MASK		= GENMASK(5, 3),
	GPIO0C1_GPIO		= 0,
	GPIO0C1_LCDC_VSYNC,
	GPIO0C1_CIF_VSYNC,
	GPIO0C1_TP8,

	GPIO0C0_SHIFT		= 0,
	GPIO0C0_MASK		= GENMASK(2, 0),
	GPIO0C0_GPIO		= 0,
	GPIO0C0_LCDC_CLK,
	GPIO0C0_CIF_CLK,
	GPIO0C0_TP7,

	/* GPIO1A_IOMUX */
	GPIO1A7_SHIFT		= 14,
	GPIO1A7_MASK		= GENMASK(15, 14),
	GPIO1A7_GPIO		= 0,
	GPIO1A7_LCDC_D11,
	GPIO1A7_CIF_D11,
	GPIO1A7_MIPI0_RX2_P,

	GPIO1A6_SHIFT		= 12,
	GPIO1A6_MASK		= GENMASK(13, 12),
	GPIO1A6_GPIO		= 0,
	GPIO1A6_LCDC_D10,
	GPIO1A6_CIF_D10,
	GPIO1A6_MIPI0_RX2_N,

	GPIO1A5_SHIFT		= 10,
	GPIO1A5_MASK		= GENMASK(11, 10),
	GPIO1A5_GPIO		= 0,
	GPIO1A5_LCDC_D9,
	GPIO1A5_CIF_D9,
	GPIO1A5_MIPI0_TCK_P,

	GPIO1A4_SHIFT		= 8,
	GPIO1A4_MASK		= GENMASK(9, 8),
	GPIO1A4_GPIO		= 0,
	GPIO1A4_LCDC_D8,
	GPIO1A4_CIF_D8,
	GPIO1A4_MIPI0_TCK_N,

	GPIO1A3_SHIFT		= 6,
	GPIO1A3_MASK		= GENMASK(7, 6),
	GPIO1A3_GPIO		= 0,
	GPIO1A3_LCDC_D7,
	GPIO1A3_CIF_D7,
	GPIO1A3_MIPI0_RX1_P,

	GPIO1A2_SHIFT		= 4,
	GPIO1A2_MASK		= GENMASK(5, 4),
	GPIO1A2_GPIO		= 0,
	GPIO1A2_LCDC_D6,
	GPIO1A2_CIF_D6,
	GPIO1A2_MIPI0_RX1_N,

	GPIO1A1_SHIFT		= 2,
	GPIO1A1_MASK		= GENMASK(3, 2),
	GPIO1A1_GPIO		= 0,
	GPIO1A1_LCDC_D5,
	GPIO1A1_CIF_D5,
	GPIO1A1_MIPI0_RX0_P,

	GPIO1A0_SHIFT		= 0,
	GPIO1A0_MASK		= GENMASK(1, 0),
	GPIO1A0_GPIO		= 0,
	GPIO1A0_LCDC_D4,
	GPIO1A0_CIF_D4,
	GPIO1A0_MIPI0_RX0_N,

	/* GPIO1B_IOMUX */
	GPIO1B7_SHIFT		= 14,
	GPIO1B7_MASK		= GENMASK(15, 14),
	GPIO1B7_GPIO		= 0,
	GPIO1B7_LCDC_D19,
	GPIO1B7_CIF_D19,
	GPIO1B7_MIPI1_TCK_P,

	GPIO1B6_SHIFT		= 12,
	GPIO1B6_MASK		= GENMASK(13, 12),
	GPIO1B6_GPIO		= 0,
	GPIO1B6_LCDC_D18,
	GPIO1B6_CIF_D18,
	GPIO1B6_MIPI1_TCK_N,

	GPIO1B5_SHIFT		= 10,
	GPIO1B5_MASK		= GENMASK(11, 10),
	GPIO1B5_GPIO		= 0,
	GPIO1B5_LCDC_D17,
	GPIO1B5_CIF_D17,
	GPIO1B5_MIPI1_RX1_P,

	GPIO1B4_SHIFT		= 8,
	GPIO1B4_MASK		= GENMASK(9, 8),
	GPIO1B4_GPIO		= 0,
	GPIO1B4_LCDC_D16,
	GPIO1B4_CIF_D16,
	GPIO1B4_MIPI1_RX1_N,

	GPIO1B3_SHIFT		= 6,
	GPIO1B3_MASK		= GENMASK(7, 6),
	GPIO1B3_GPIO		= 0,
	GPIO1B3_LCDC_D15,
	GPIO1B3_CIF_D15,
	GPIO1B3_MIPI1_RX0_P,

	GPIO1B2_SHIFT		= 4,
	GPIO1B2_MASK		= GENMASK(5, 4),
	GPIO1B2_GPIO		= 0,
	GPIO1B2_LCDC_D14,
	GPIO1B2_CIF_D14,
	GPIO1B2_MIPI1_RX0_N,

	GPIO1B1_SHIFT		= 2,
	GPIO1B1_MASK		= GENMASK(3, 2),
	GPIO1B1_GPIO		= 0,
	GPIO1B1_LCDC_D13,
	GPIO1B1_CIF_D13,
	GPIO1B1_MIPI0_RX3_P,

	GPIO1B0_SHIFT		= 0,
	GPIO1B0_MASK		= GENMASK(1, 0),
	GPIO1B0_GPIO		= 0,
	GPIO1B0_LCDC_D12,
	GPIO1B0_CIF_D12,
	GPIO1B0_MIPI0_RX3_N,

	/* GPIO1C_IOMUX */
	GPIO1C3_SHIFT		= 6,
	GPIO1C3_MASK		= GENMASK(7, 6),
	GPIO1C3_GPIO		= 0,
	GPIO1C3_LCDC_D23,
	GPIO1C3_CIF_D23,
	GPIO1C3_MIPI1_RX3_P,

	GPIO1C2_SHIFT		= 4,
	GPIO1C2_MASK		= GENMASK(5, 4),
	GPIO1C2_GPIO		= 0,
	GPIO1C2_LCDC_D22,
	GPIO1C2_CIF_D22,
	GPIO1C2_MIPI1_RX3_N,

	GPIO1C1_SHIFT		= 2,
	GPIO1C1_MASK		= GENMASK(3, 2),
	GPIO1C1_GPIO		= 0,
	GPIO1C1_LCDC_D21,
	GPIO1C1_CIF_D21,
	GPIO1C1_MIPI1_RX2_P,

	GPIO1C0_SHIFT		= 0,
	GPIO1C0_MASK		= GENMASK(1, 0),
	GPIO1C0_GPIO		= 0,
	GPIO1C0_LCDC_D20,
	GPIO1C0_CIF_D20,
	GPIO1C0_MIPI1_RX2_N,
};

#define SER_GRF_SOC_CON0		SER_GRF_REG(0x0100)
#define SER_GRF_SOC_CON1		SER_GRF_REG(0x0104)
#define SER_GRF_SOC_CON2		SER_GRF_REG(0x0108)
#define SER_GRF_SOC_CON3		SER_GRF_REG(0x010c)
#define SER_GRF_SOC_CON4		SER_GRF_REG(0x0110)
#define SER_GRF_SOC_CON5		SER_GRF_REG(0x0114)
#define SER_GRF_SOC_CON6		SER_GRF_REG(0x0118)
#define SER_GRF_SOC_CON7		SER_GRF_REG(0x011c)
#define SER_GRF_SOC_STATUS0		SER_GRF_REG(0x0160)

enum {
	/* SOC_CON0 */

	/* SOC_CON2 */

	/* SOC_CON3 */
	AUDIO_PCS_SEL_SHIFT	= 15,
	AUDIO_PCS_SEL_MASK	= HIWORD_MASK(15, 15),
	AUDIO_SEL_PCS0		= HIWORD_UPDATE(0, BIT(15), 15),
	AUDIO_SEL_PCS1		= HIWORD_UPDATE(1, BIT(15), 15),

	CMD_PCS_SEL_SHIFT	= 14,
	CMD_PCS_SEL_MASK	= HIWORD_MASK(14, 14),
	CMD_SEL_PCS0		= HIWORD_UPDATE(0, BIT(14), 14),
	CMD_SEL_PCS1		= HIWORD_UPDATE(1, BIT(14), 14),

	/* SOC_CON4 */

	/* SOC_CON5 */
	LDO_PLC_SEL_SHIFT	= 8,
	LDO_PLC_SEL_MASK	= HIWORD_MASK(8, 8),

	LDO_VOL_SEL_SHIFT	= 4,
	LDO_VOL_SEL_MASK	= HIWORD_MASK(7, 4),

	LDO_BG_TRIM_SHIFT	= 0,
	LDO_BG_TRIM_MASK	= HIWORD_MASK(3, 0),

	/* SOC_CON7 */
	PMA_PLL_CTRL_SEL_SHIFT	= 15,
	PMA_PLL_CTRL_SEL_MASK	= HIWORD_MASK(15, 15),
	PMA_PLL_CTRL_BY_PMA0	= HIWORD_UPDATE(0, BIT(15), 15),
	PMA_PLL_CTRL_BY_PMA1	= HIWORD_UPDATE(1, BIT(15), 15),

	PMA1_EN_SHIFT		= 9,
	PMA1_EN_MASK		= HIWORD_MASK(9, 9),
	PMA1_ENABLE		= HIWORD_UPDATE(1, BIT(9), 9),
	PMA1_DISABLE		= HIWORD_UPDATE(0, BIT(9), 9),

	PMA0_EN_SHIFT		= 8,
	PMA0_EN_MASK		= HIWORD_MASK(8, 8),
	PMA0_ENABLE		= HIWORD_UPDATE(1, BIT(8), 8),
	PMA0_DISABLE		= HIWORD_UPDATE(0, BIT(8), 8),

	/* SER_GRF_IRQ_EN */
	SER_IRQ_OTHER_LANE_EN	= HIWORD_UPDATE(1, BIT(15), 15),
	SER_IRQ_OTHER_LANE_DIS	= HIWORD_UPDATE(0, BIT(15), 15),

	SER_IRQ_LINK_EN		= HIWORD_UPDATE(1, BIT(14), 14),
	SER_IRQ_LINK_DIS	= HIWORD_UPDATE(0, BIT(14), 14),

	SER_IRQ_EXT_EN		= HIWORD_UPDATE(1, BIT(13), 13),
	SER_IRQ_EXT_DIS		= HIWORD_UPDATE(0, BIT(13), 13),

	SER_IRQ_REMOTE_EN	= HIWORD_UPDATE(1, BIT(12), 12),
	SER_IRQ_REMOTE_DIS	= HIWORD_UPDATE(0, BIT(12), 12),

	SER_IRQ_VICAP_EN	= HIWORD_UPDATE(1, BIT(11), 11),
	SER_IRQ_VICAP_DIS	= HIWORD_UPDATE(0, BIT(11), 11),

	SER_IRQ_EFUSE_EN	= HIWORD_UPDATE(1, BIT(10), 10),
	SER_IRQ_EFUSE_DIS	= HIWORD_UPDATE(0, BIT(10), 10),

	SER_IRQ_PMA_ADAPT1_EN	= HIWORD_UPDATE(1, BIT(9), 9),
	SER_IRQ_PMA_ADAPT1_DIS	= HIWORD_UPDATE(0, BIT(9), 9),

	SER_IRQ_PMA_ADAPT0_EN	= HIWORD_UPDATE(1, BIT(8), 8),
	SER_IRQ_PMA_ADAPT0_DIS	= HIWORD_UPDATE(0, BIT(8), 8),

	SER_IRQ_CSIHOST1_EN	= HIWORD_UPDATE(1, BIT(7), 7),
	SER_IRQ_CSIHOST1_DIS	= HIWORD_UPDATE(0, BIT(7), 7),

	SER_IRQ_CSIHOST0_EN	= HIWORD_UPDATE(1, BIT(6), 6),
	SER_IRQ_CSIHOST0_DIS	= HIWORD_UPDATE(0, BIT(6), 6),

	SER_IRQ_GPIO1_EN	= HIWORD_UPDATE(1, BIT(5), 5),
	SER_IRQ_GPIO1_DIS	= HIWORD_UPDATE(0, BIT(5), 5),

	SER_IRQ_GPIO0_EN	= HIWORD_UPDATE(1, BIT(4), 4),
	SER_IRQ_GPIO0_DIS	= HIWORD_UPDATE(0, BIT(4), 4),

	SER_IRQ_DSIRX1_EN	= HIWORD_UPDATE(1, BIT(3), 3),
	SER_IRQ_DSIRX1_DIS	= HIWORD_UPDATE(0, BIT(3), 3),

	SER_IRQ_DSIRX0_EN	= HIWORD_UPDATE(1, BIT(2), 2),
	SER_IRQ_DSIRX0_DIS	= HIWORD_UPDATE(0, BIT(2), 2),

	SER_IRQ_PCS1_EN		= HIWORD_UPDATE(1, BIT(1), 1),
	SER_IRQ_PCS1_DIS	= HIWORD_UPDATE(0, BIT(1), 1),

	SER_IRQ_PCS0_EN		= HIWORD_UPDATE(1, BIT(0), 0),
	SER_IRQ_PCS0_DIS	= HIWORD_UPDATE(0, BIT(0), 0),

	/* SER_GRF_IRQ_STATUS */
	SER_IRQ_OTHER_LANE	= BIT(15),
	SER_IRQ_LINK		= BIT(14),
	SER_IRQ_EXT		= BIT(13),
	SER_IRQ_REMOTE		= BIT(12),
	SER_IRQ_VICAP		= BIT(11),
	SER_IRQ_EFUSE		= BIT(10),
	SER_IRQ_PMA_ADAPT1	= BIT(9),
	SER_IRQ_PMA_ADAPT0	= BIT(8),
	SER_IRQ_CSIHOST1	= BIT(7),
	SER_IRQ_CSIHOST0	= BIT(6),
	SER_IRQ_GPIO1		= BIT(5),
	SER_IRQ_GPIO0		= BIT(4),
	SER_IRQ_DSIRX1		= BIT(3),
	SER_IRQ_DSIRX0		= BIT(2),
	SER_IRQ_PCS1		= BIT(1),
	SER_IRQ_PCS0		= BIT(0),

	/* SER_GRF_SOC_STATUS0 */
	SER_PCS1_READY		= BIT(21),
	SER_PCS0_READY		= BIT(20),
};

#define RKX11X_CSI2HOST0_BASE		0x00020000
#define RKX11X_CSI2HOST1_BASE		0x00028000
#define RKX11X_VICAP_BASE		0x00030000
#define RKX11X_GPIO0_BASE		0x00040000

#define RKX11X_DSI_RX0_BASE		0x00060000
#define RKX11X_DSI_RX1_BASE		0x00068000
#define RKX11X_SER_RKLINK_BASE		0x00070000
#define RKX11X_SER_PCS0_BASE		0x00074000
#define RKX11X_SER_PCS1_BASE		0x00075000
#define RKX11X_EFUSE_BASE		0x00800000
#define RKX11X_MIPI_LVDS_RX_PHY0_BASE	0x00090000
#define RKX11X_GRF_MIPI0_BASE		0x000A0000
#define RKX11X_MIPI_LVDS_RX_PHY1_BASE	0x000B0000
#define RKX11X_GRF_MIPI1_BASE		0x000C0000
#define RKX11X_SER_PMA0_BASE		0x000D0000
#define RKX11X_SER_PMA1_BASE		0x000E0000

#define RKX11X_GPIO1_BASE		0x000F0000

#define RKX11X_PATTERN_GEN_DSI0_BASE	0x00100000
#define RKX11X_PATTERN_GEN_DSI1_BASE	0x00110000
#define RKX11X_PATTERN_GEN_LVDS0_BASE	0x00120000
#define RKX11X_PATTERN_GEN_LVDS1_BASE	0x00130000

#define RKX11X_LBIST_ADA_BASE		0x00150000

#endif /* __RKX11X_REG_H__ */