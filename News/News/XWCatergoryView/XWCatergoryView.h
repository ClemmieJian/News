//
//  XWCatergoryView.h
//  XWCatergoryView
//
//  Created by YouLoft_MacMini on 16/02/24.
//  Copyright © 2016年 wazrx. All rights reserved.
//
/**
 一、是什么：XWCatergoryView是一个轻量级的顶部分类视图控件，只需要通过简单的设置，你就可以快速集成该控件， 控件目前暂时有底部横条移动，椭圆背景移动，文字缩放，文字颜色变化，和文字颜色渐变五种效果，五种效果可以叠加使用也可以单一使用，具体效果请查看demo,
 */

/**
 二、如何使用：
 1、导入`XWCatergoryView.h`头文件
 
 2、如果是当前控制器是被导航控制器管理，也就是说上方有导航栏，必须对当前控制器做如下设置：`self.automaticallyAdjustsScrollViewInsets = NO;`否则控件显示会有问题
 
 3、初始化该控件，代码和stroyboard都可以，stroyboard的话，直接拖入一个View并修改Class为`XWCatergoryView`即可;
 
 4、设置数据源titles属性（必须）
 
 5、设置与该控件关联的ScrollView（必须）
 
 6、配置相关的属性即可使用，可自定义的属性比较多，请自行去`XWCatergoryView.h`中查看，更详请见地址中的demo
 */

#import <UIKit/UIKit.h>

@class XWCatergoryView;

@protocol XWCatergoryViewDelegate <NSObject>

@optional
/**
 *  点击了item
 *
 *  @param catergoryView self
 *  @param indexPath     item的indexPath
 */
- (void)catergoryView:(XWCatergoryView *)catergoryView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

@end



@interface XWCatergoryView : UIView

#pragma mark - basic

/**所管理滚动的scrollView或者其子类，一般使用collectionView, 必须设置*/
@property (nonatomic, weak) UIScrollView *scrollView;

/**数据源titles，必须设置*/
@property (nonatomic, copy) NSArray *titles;

/**点击item后各个控件（底部线条和椭圆）动画的时间，默认0.3秒，可设置为0*/
@property (nonatomic, assign) NSTimeInterval clickedAnimationDuration;

/**当点击item滚动传入的scrollView是，是否使用动画，默认YES*/
@property (nonatomic, assign) BOOL scrollWithAnimaitonWhenClicked;

/**代理，可监听item按钮点击*/
@property (nonatomic, assign) id<XWCatergoryViewDelegate> delegate;

#pragma mark - item

/**item间距，默认10，如果计算出的item排布的总宽度小于控件宽度，会自动修改item让item均布*/
@property (nonatomic, assign) CGFloat itemSpacing;
/**左右边缘间距，默认20*/
@property (nonatomic, assign) CGFloat edgeSpacing;
/**item字体，默认15*/
@property (nonatomic, strong) UIFont *titleFont;

#pragma mark - titleColor

/**是否开启文字颜色变化效果，默认YES*/
@property (nonatomic, assign) BOOL titleColorChangeEable;
/**是否开启文字颜色变化渐变，默认NO，如果设置该效果YES需要先保证titleColorChangeEable为YES*/
@property (nonatomic, assign) BOOL titleColorChangeGradually;
/**edge间距， 默认 白色*/
@property (nonatomic, strong) UIColor *titleColor;
/**edge间距， 默认 红色*/
@property (nonatomic, strong) UIColor *titleSelectColor;


#pragma mark - scale

/**是否开启缩放， 默认NO*/
@property (nonatomic, assign) BOOL scaleEnable;
/**缩放比例， 默认1.1*/
@property (nonatomic, assign) CGFloat scaleRatio;

#pragma mark - bottomLine

/**是否开启下方横线，默认NO*/
@property (nonatomic, assign) BOOL bottomLineEable;
/**下方横线颜色，默认红色*/
@property (nonatomic, strong) UIColor *bottomLineColor;
/**下方横线宽度，默认2.0f*/
@property (nonatomic, assign) CGFloat bottomLineWidth;
/**下方横线距离item底部的距离，默认10.0f*/
@property (nonatomic, assign) CGFloat bottomLineSpacingFromTitleBottom;

#pragma mark - backEllipse

/**是否隐藏背后的椭圆，默认YES*/
@property (nonatomic, assign) BOOL backEllipseEable;
/**椭圆颜色，默认黄色*/
@property (nonatomic, strong) UIColor *backEllipseColor;

/**重新设置titles数据源后调用该方法刷新控件*/
- (void)xw_realoadData;

@end
