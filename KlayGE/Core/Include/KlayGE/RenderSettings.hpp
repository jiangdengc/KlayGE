// RenderSettings.hpp
// KlayGE 渲染设置类 实现文件
// Ver 3.10.0
// 版权所有(C) 龚敏敏, 2005-2010
// Homepage: http://klayge.sourceforge.net
//
// 3.10.0
// 增加了motion_frames (2010.2.22)
// 支持Stereo (2010.3.20)
//
// 3.7.0
// 去掉了ConfirmDevice的参数 (2008.3.17)
//
// 2.8.0
// 加入了ConfirmDevice (2005.7.17)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef _RENDERSETTINGS_HPP
#define _RENDERSETTINGS_HPP

#pragma once

#include <boost/function.hpp>

#include <KlayGE/ElementFormat.hpp>

namespace KlayGE
{
	// 建立渲染窗口的设置
	/////////////////////////////////////////////////////////////////////////////////
	struct RenderSettings
	{
		RenderSettings()
			: full_screen(false),
				left(0), top(0),
				color_fmt(EF_ARGB8), depth_stencil_fmt(EF_D16),
				sample_count(1), sample_quality(0),
				motion_frames(0),
				stereo_mode(false), stereo_separation(0)
		{
		}

		boost::function<bool()> ConfirmDevice;

		bool	full_screen;
		int		left;
		int		top;
		int		width;
		int		height;
		ElementFormat color_fmt;
		ElementFormat depth_stencil_fmt;
		uint32_t sample_count;
		uint32_t sample_quality;
		uint32_t motion_frames;
		bool stereo_mode;
		float stereo_separation;
	};
}

#endif			// _RENDERSETTINGS_HPP
