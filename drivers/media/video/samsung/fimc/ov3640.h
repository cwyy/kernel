#ifndef __OV3640_H__
#define __OV3640_H__

#define OV3640_COMPLETE

struct ov3640_reg {
	unsigned char addr;
	unsigned char val;
};

struct ov3640_regset_type {
	unsigned char *regset;
	int len;
};

/*
 * Macro
 */
#define REGSET_LENGTH(x)	(sizeof(x)/sizeof(ov3640_reg))

/*
 * User defined commands
 */
/* S/W defined features for tune */
#define REG_DELAY	0xFF00	/* in ms */
#define REG_CMD		0xFFFF	/* Followed by command */

/* Following order should not be changed */
enum image_size_ov3640 {
	/* This SoC supports upto UXGA (1600*1200) */
#if 0
	QQVGA,	/* 160*120*/
	QCIF,	/* 176*144 */
	QVGA,	/* 320*240 */
	CIF,	/* 352*288 */
#endif
	VGA,	/* 640*480 */
#if 0
	SVGA,	/* 800*600 */
	HD720P,	/* 1280*720 */
	SXGA,	/* 1280*1024 */
	UXGA,	/* 1600*1200 */
#endif
};

/*
 * Following values describe controls of camera
 * in user aspect and must be match with index of ov3640_regset[]
 * These values indicates each controls and should be used
 * to control each control
 */
enum ov3640_control {
	OV3640_INIT,
	OV3640_EV,
	OV3640_AWB,
	OV3640_MWB,
	OV3640_EFFECT,
	OV3640_CONTRAST,
	OV3640_SATURATION,
	OV3640_SHARPNESS,
};

#define OV3640_REGSET(x)	{	\
	.regset = x,			\
	.len = sizeof(x)/sizeof(ov3640_reg),}


/*
 * User tuned register setting values
 */
u8 ov3640_setting_15fps_VGA_640_480[][3] = {
//u8 ov3640_init_reg[][3] = {
      {0x30,0x12, 0x80}, {0x30,0x4d, 0x45}, {0x30,0xa7, 0x5e},
      {0x30,0x87, 0x16}, {0x30,0x9c, 0x1a}, {0x30,0xa2, 0xe4},
      {0x30,0xaa, 0x42}, {0x30,0xa9, 0xb5}, {0x30,0xb0, 0xff},
      {0x30,0xb1, 0xff}, {0x30,0xb2, 0x18}, {0x30,0x0e, 0x32},
      {0x30,0x0f, 0x21}, {0x30,0x10, 0x20}, {0x30,0x11, 0x04},
      {0x30,0x4c, 0x81}, {0x30,0xd7, 0x10}, {0x30,0xd9, 0x0d},
      {0x30,0xdb, 0x08}, {0x30,0x16, 0x82}, {0x30,0x18, 0x38},
      {0x30,0x19, 0x30}, {0x30,0x1a, 0x61}, {0x30,0x7d, 0x00},
      {0x30,0x87, 0x02}, {0x30,0x82, 0x20}, {0x30,0x15, 0x12},
      {0x30,0x14, 0x84}, {0x30,0x16, 0x92}, {0x30,0x13, 0xf7},
      {0x30,0x3c, 0x08}, {0x30,0x3d, 0x18}, {0x30,0x3e, 0x06},
      {0x30,0x3f, 0x0c}, {0x30,0x30, 0x62}, {0x30,0x31, 0x26},
      {0x30,0x32, 0xe6}, {0x30,0x33, 0x6e}, {0x30,0x34, 0xea},
      {0x30,0x35, 0xae}, {0x30,0x36, 0xa6}, {0x30,0x37, 0x6a},
      {0x31,0x04, 0x02}, {0x31,0x05, 0xfd}, {0x31,0x06, 0x00},
      {0x31,0x07, 0xff}, {0x33,0x01, 0xde}, {0x33,0x02, 0xef},
      {0x33,0x12, 0x26}, {0x33,0x14, 0x42}, {0x33,0x13, 0x2b},
      {0x33,0x15, 0x42}, {0x33,0x10, 0xd0}, {0x33,0x11, 0xbd},
      {0x33,0x0c, 0x18}, {0x33,0x0d, 0x18}, {0x33,0x0e, 0x56},
      {0x33,0x0f, 0x5c}, {0x33,0x0b, 0x1c}, {0x33,0x06, 0x5c},
      {0x33,0x07, 0x11}, {0x33,0x6a, 0x52}, {0x33,0x70, 0x46},
      {0x33,0x76, 0x38}, {0x33,0x00, 0x13}, {0x30,0xb8, 0x20},
      {0x30,0xb9, 0x17}, {0x30,0xba, 0x02}, {0x30,0xbb, 0x08},
      {0x35,0x07, 0x06}, {0x35,0x0a, 0x4f}, {0x31,0x00, 0x02},
      {0x33,0x01, 0xde}, {0x33,0x04, 0x00}, {0x34,0x00, 0x00},
      {0x34,0x04, 0x02}, {0x33,0x5f, 0x68}, {0x33,0x60, 0x18},
      {0x33,0x61, 0x0c}, {0x33,0x62, 0x12}, {0x33,0x63, 0x88},
      {0x33,0x64, 0xe4}, {0x34,0x03, 0x42}, {0x30,0x88, 0x02},
      {0x30,0x89, 0x80}, {0x30,0x8a, 0x01}, {0x30,0x8b, 0xe0},
      {0x30,0xd7, 0x10}, {0x33,0x02, 0xef}, {0x33,0x5f, 0x68},
      {0x33,0x60, 0x18}, {0x33,0x61, 0x0c}, {0x33,0x62, 0x12},
      {0x33,0x63, 0x88}, {0x33,0x64, 0xe4}, {0x34,0x03, 0x42},
      {0x30,0x88, 0x12}, {0x30,0x89, 0x80}, {0x30,0x8a, 0x01},
      {0x30,0x8b, 0xe0}, {0x30,0x4c, 0x84}, {0x33,0x2a, 0x18},
      {0x33,0x1b, 0x04}, {0x33,0x1c, 0x13}, {0x33,0x1d, 0x2b},
      {0x33,0x1e, 0x53}, {0x33,0x1f, 0x66}, {0x33,0x20, 0x73},
      {0x33,0x21, 0x80}, {0x33,0x22, 0x8c}, {0x33,0x23, 0x95},
      {0x33,0x24, 0x9d}, {0x33,0x25, 0xac}, {0x33,0x26, 0xb8},
      {0x33,0x27, 0xcc}, {0x33,0x28, 0xdd}, {0x33,0x29, 0xee},
      {0x33,0x00, 0x13}, {0x33,0x67, 0x23}, {0x33,0x68, 0xb5},
      {0x33,0x69, 0xc8}, {0x33,0x6A, 0x46}, {0x33,0x6B, 0x07},
      {0x33,0x6C, 0x00}, {0x33,0x6D, 0x23}, {0x33,0x6E, 0xbb},
      {0x33,0x6F, 0xcc}, {0x33,0x70, 0x49}, {0x33,0x71, 0x07},
      {0x33,0x72, 0x00}, {0x33,0x73, 0x23}, {0x33,0x74, 0xab},
      {0x33,0x75, 0xcc}, {0x33,0x76, 0x46}, {0x33,0x77, 0x07},
      {0x33,0x78, 0x00}, {0x33,0x2a, 0x1d}, {0x33,0x1b, 0x08}, 
      {0x33,0x1c, 0x16}, {0x33,0x1d, 0x2d}, {0x33,0x1e, 0x54},
      {0x33,0x1f, 0x66}, {0x33,0x20, 0x73}, {0x33,0x21, 0x80},
      {0x33,0x22, 0x8c}, {0x33,0x23, 0x95}, {0x33,0x24, 0x9d},
      {0x33,0x25, 0xac}, {0x33,0x26, 0xb8}, {0x33,0x27, 0xcc},
      {0x33,0x28, 0xdd}, {0x33,0x29, 0xee}, {0x33,0x17, 0x04},
      {0x33,0x16, 0xf8}, {0x33,0x12, 0x31}, {0x33,0x14, 0x57},
      {0x33,0x13, 0x28}, {0x33,0x15, 0x3d}, {0x33,0x11, 0xd0},
      {0x33,0x10, 0xb6}, {0x33,0x0c, 0x16}, {0x33,0x0d, 0x16},
      {0x33,0x0e, 0x5F}, {0x33,0x0f, 0x5C}, {0x33,0x0b, 0x18},
      {0x33,0x06, 0x5c}, {0x33,0x07, 0x11}, {0x33,0x08, 0x25},
      {0x33,0x18, 0x62}, {0x33,0x19, 0x62}, {0x33,0x1a, 0x62},
      {0x33,0x40, 0x20}, {0x33,0x41, 0x58}, {0x33,0x42, 0x08},
      {0x33,0x43, 0x21}, {0x33,0x44, 0xbe}, {0x33,0x45, 0xe0},
      {0x33,0x46, 0xca}, {0x33,0x47, 0xc6}, {0x33,0x48, 0x04},
      {0x33,0x49, 0x98}, {0x33,0x3F, 0x06}, {0x33,0x2e, 0x04},
      {0x33,0x2f, 0x05}, {0x33,0x31, 0x03}, {0x30,0x2B, 0x6D},
      {0x30,0x8d, 0x04}, {0x30,0x86, 0x03}, {0x30,0x86, 0x00},
      {0x30,0x7d, 0x00}, {0x30,0x85, 0x00}, {0x30,0x6c, 0x10},
      {0x30,0x7b, 0x40}, {0x36,0x1d, 0x50}, {0x31,0x00, 0x02},
      {0x33,0x01, 0xde}, {0x33,0x04, 0x00}, {0x34,0x00, 0x00},
      {0x34,0x04, 0x00}, {0x30,0x12, 0x10}, {0x30,0x23, 0x06},
      {0x30,0x26, 0x03}, {0x30,0x27, 0x04}, {0x30,0x2a, 0x03},
      {0x30,0x2b, 0x10}, {0x30,0x75, 0x24}, {0x30,0x0d, 0x01},
      {0x30,0xd7, 0x90}, {0x30,0x69, 0x04}, {0x30,0x3e, 0x00},
      {0x30,0x3f, 0xc0}, {0x33,0x02, 0xef}, {0x33,0x5f, 0x34},
      {0x33,0x60, 0x0c}, {0x33,0x61, 0x04}, {0x33,0x62, 0x34},
      {0x33,0x63, 0x08}, {0x33,0x64, 0x04}, {0x34,0x03, 0x42},
      {0x30,0x88, 0x04}, {0x30,0x89, 0x00}, {0x30,0x8a, 0x03},
      {0x30,0x8b, 0x00}, {0x30,0x0e, 0x32}, {0x30,0x0f, 0x21},
      {0x30,0x10, 0x20}, {0x30,0x11, 0x01}, {0x30,0x4c, 0x82},
      {0x33,0x02, 0xef}, {0x33,0x5f, 0x34}, {0x33,0x60, 0x0c},
      {0x33,0x61, 0x04}, {0x33,0x62, 0x12}, {0x33,0x63, 0x88},
      {0x33,0x64, 0xe4}, {0x34,0x03, 0x42}, {0x30,0x88, 0x12},
      {0x30,0x89, 0x80}, {0x30,0x8a, 0x01}, {0x30,0x8b, 0xe0},
      {0x30,0x4c, 0x85}, {0x30,0x0e, 0x39}, {0x30,0x0f, 0x21},
      {0x30,0x11, 0x00}, {0x30,0x10, 0x81}, {0x30,0x2e, 0x00},  
      {0x30,0x2d, 0x00}, {0x30,0x71, 0xeb}, {0x30,0x1C, 0x02}
};


#define OV3640_INIT_REGS	((sizeof(ov3640_setting_15fps_VGA_640_480)/sizeof(ov3640_setting_15fps_VGA_640_480[0])))

/*
 * EV bias
 */

static const struct ov3640_reg ov3640_ev_m6[] = {
};

static const struct ov3640_reg ov3640_ev_m5[] = {
};

static const struct ov3640_reg ov3640_ev_m4[] = {
};

static const struct ov3640_reg ov3640_ev_m3[] = {
};

static const struct ov3640_reg ov3640_ev_m2[] = {
};

static const struct ov3640_reg ov3640_ev_m1[] = {
};

static const struct ov3640_reg ov3640_ev_default[] = {
};

static const struct ov3640_reg ov3640_ev_p1[] = {
};

static const struct ov3640_reg ov3640_ev_p2[] = {
};

static const struct ov3640_reg ov3640_ev_p3[] = {
};

static const struct ov3640_reg ov3640_ev_p4[] = {
};

static const struct ov3640_reg ov3640_ev_p5[] = {
};

static const struct ov3640_reg ov3640_ev_p6[] = {
};

#ifdef OV3640_COMPLETE
/* Order of this array should be following the querymenu data */
static const unsigned char *ov3640_regs_ev_bias[] = {
	(unsigned char *)ov3640_ev_m6, (unsigned char *)ov3640_ev_m5,
	(unsigned char *)ov3640_ev_m4, (unsigned char *)ov3640_ev_m3,
	(unsigned char *)ov3640_ev_m2, (unsigned char *)ov3640_ev_m1,
	(unsigned char *)ov3640_ev_default, (unsigned char *)ov3640_ev_p1,
	(unsigned char *)ov3640_ev_p2, (unsigned char *)ov3640_ev_p3,
	(unsigned char *)ov3640_ev_p4, (unsigned char *)ov3640_ev_p5,
	(unsigned char *)ov3640_ev_p6,
};

/*
 * Auto White Balance configure
 */
static const struct ov3640_reg ov3640_awb_off[] = {
};

static const struct ov3640_reg ov3640_awb_on[] = {
};

static const unsigned char *ov3640_regs_awb_enable[] = {
	(unsigned char *)ov3640_awb_off,
	(unsigned char *)ov3640_awb_on,
};

/*
 * Manual White Balance (presets)
 */
static const struct ov3640_reg ov3640_wb_tungsten[] = {

};

static const struct ov3640_reg ov3640_wb_fluorescent[] = {

};

static const struct ov3640_reg ov3640_wb_sunny[] = {

};

static const struct ov3640_reg ov3640_wb_cloudy[] = {

};

/* Order of this array should be following the querymenu data */
static const unsigned char *ov3640_regs_wb_preset[] = {
	(unsigned char *)ov3640_wb_tungsten,
	(unsigned char *)ov3640_wb_fluorescent,
	(unsigned char *)ov3640_wb_sunny,
	(unsigned char *)ov3640_wb_cloudy,
};

/*
 * Color Effect (COLORFX)
 */
static const struct ov3640_reg ov3640_color_sepia[] = {
};

static const struct ov3640_reg ov3640_color_aqua[] = {
};

static const struct ov3640_reg ov3640_color_monochrome[] = {
};

static const struct ov3640_reg ov3640_color_negative[] = {
};

static const struct ov3640_reg ov3640_color_sketch[] = {
};

/* Order of this array should be following the querymenu data */
static const unsigned char *ov3640_regs_color_effect[] = {
	(unsigned char *)ov3640_color_sepia,
	(unsigned char *)ov3640_color_aqua,
	(unsigned char *)ov3640_color_monochrome,
	(unsigned char *)ov3640_color_negative,
	(unsigned char *)ov3640_color_sketch,
};

/*
 * Contrast bias
 */
static const struct ov3640_reg ov3640_contrast_m2[] = {
};

static const struct ov3640_reg ov3640_contrast_m1[] = {
};

static const struct ov3640_reg ov3640_contrast_default[] = {
};

static const struct ov3640_reg ov3640_contrast_p1[] = {
};

static const struct ov3640_reg ov3640_contrast_p2[] = {
};

static const unsigned char *ov3640_regs_contrast_bias[] = {
	(unsigned char *)ov3640_contrast_m2,
	(unsigned char *)ov3640_contrast_m1,
	(unsigned char *)ov3640_contrast_default,
	(unsigned char *)ov3640_contrast_p1,
	(unsigned char *)ov3640_contrast_p2,
};

/*
 * Saturation bias
 */
static const struct ov3640_reg ov3640_saturation_m2[] = {
};

static const struct ov3640_reg ov3640_saturation_m1[] = {
};

static const struct ov3640_reg ov3640_saturation_default[] = {
};

static const struct ov3640_reg ov3640_saturation_p1[] = {
};

static const struct ov3640_reg ov3640_saturation_p2[] = {
};

static const unsigned char *ov3640_regs_saturation_bias[] = {
	(unsigned char *)ov3640_saturation_m2,
	(unsigned char *)ov3640_saturation_m1,
	(unsigned char *)ov3640_saturation_default,
	(unsigned char *)ov3640_saturation_p1,
	(unsigned char *)ov3640_saturation_p2,
};

/*
 * Sharpness bias
 */
static const struct ov3640_reg ov3640_sharpness_m2[] = {
};

static const struct ov3640_reg ov3640_sharpness_m1[] = {
};

static const struct ov3640_reg ov3640_sharpness_default[] = {
};

static const struct ov3640_reg ov3640_sharpness_p1[] = {
};

static const struct ov3640_reg ov3640_sharpness_p2[] = {
};

static const unsigned char *ov3640_regs_sharpness_bias[] = {
	(unsigned char *)ov3640_sharpness_m2,
	(unsigned char *)ov3640_sharpness_m1,
	(unsigned char *)ov3640_sharpness_default,
	(unsigned char *)ov3640_sharpness_p1,
	(unsigned char *)ov3640_sharpness_p2,
};
#endif /* OV3640_COMPLETE */

#endif