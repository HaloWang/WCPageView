//
//  HaloObjC.h
//  HaloObjC
//
//  Created by 王策 on 16/3/16.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - 固定尺寸
extern CGRect  ScreenBounds;
extern CGFloat ScreenWidth;
extern CGFloat ScreenHeight;
extern CGFloat NavigationBarHeight;
extern CGFloat TabBarHeight;
extern CGFloat StatusBarHeight;

#pragma mark - 沙盒路径
extern NSString *HomePath;
extern NSString *DocumentPath;
extern NSString *LibraryPath;
extern NSString *CachePath;
extern NSString *TempPath;

#pragma mark - Bundle
extern NSString *MainBundlePath;
extern NSString *ResourcePath;
extern NSString *ExecutablePath;

#pragma mark - 应用信息
extern NSString *AppBundleID;
extern NSString *AppVersion;
extern NSString *AppBuildVersion;

#pragma mark - 系统信息
extern NSString *SystemVersion;
extern float SystemVersionNumber;

extern BOOL iPhone5_5;
extern BOOL iPhone4_7;
extern BOOL iPhone4_0;
extern BOOL iPhone3_5;


#pragma mark - Measure

/**
 *  测量某段代码的执行时间
 *  你不用考虑 block 执行的线程
 *
 *  @param ^CodeWaitingForMeasure 你想测量的代码
 */
void Measure(void(^CodeWaitingForMeasure)());

#pragma mark - GCD

/**
 *  开辟新线程，异步执行
 *
 *  @param ^noUITask 一些要做，但是可以放到最后做的事情
 */
void Async(void(^noUITask)());

/**
 *  开启新线程，异步执行，完成后回到主线程执行
 *
 *  @param ^noUITask    顾名思义
 *
 *  @param ^UITask  顾名思义
 */
void AsyncFinish(void(^noUITask)(), void(^UITask)());

/**
 *  主线程异步执行
 *
 *  @param ^UITask 一些要做，而且需要在主线程做，但是可以放到最后做的事情
 */
void hl_last(void(^UITask)());

/**
 *  延迟执行
 *
 *  @param second  延迟多少秒
 *  @param ^UITask 在主线程中做的事情
 */
void hl_after(float second, void(^UITask)());


/**
 后台线程执行

 @param ^noUITask 非 UI 任务
 */
void hl_background(void(^noUITask)());

#pragma mark - Log

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print
 */
void cc(id obj);

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print with ✅
 */
void ccRight(id obj);

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print with ❌
 */
void ccError(id obj);

/**
 *  简化 NSLog 调用
 *
 *  @param obj Something you wants to print with ⚠️
 */
void ccWarning(id obj);

#pragma mark - HaloObjC

@interface HaloObjC : NSObject

/**
 *  是否开启 Log（也就是 ccLog），默认值是 YES
 */
+ (void)logEnable:(BOOL)enable;

/**
 *  如果要使用 HaloObjC 该方法必须被调用
 */
+ (void)server;

/**
 *  调用 ccError 时的回调
 */
+ (void)setCCErrorFunctionCallBack:(void(^)(NSString *displayInfo))callBack;

@end

#pragma mark - NSString

@interface NSString (Halo)

@property (nonatomic, readonly) NSURL *URL;

@property (nonatomic, readonly) NSDictionary *hl_jsonDictionary;

@end

#pragma mark - UIFont

UIFont *hl_systemFontOfSize(CGFloat size);

#pragma mark - UIButton

@interface UIButton (Halo)

@property (nonatomic, strong) UIFont *hl_titleFont;
@property (nonatomic, strong) UIColor *hl_normalTitleColor;
@property (nonatomic, strong) NSString *hl_normalTitle;
@property (nonatomic, strong) UIImage *hl_normalImage;

+ (UIButton *)custom;

- (instancetype)addTouchUpInSideTarget:(id)target action:(SEL)action;

@end

#pragma mark - UIView

/// 相当于 CGRectMake
CGRect RM(CGFloat x, CGFloat y, CGFloat width, CGFloat height);

/// 创建一个水平居中（相对于屏幕）的 CGRect 值
CGRect CM(CGFloat y, CGFloat width, CGFloat height);

/// 像素对齐
CGFloat pixelIntegral(CGFloat value);

@interface UIView (Halo)

+ (instancetype)addToSuperview:(UIView *)superview;

- (instancetype)addToSuperview:(UIView *)superview;

/**
 *  设定圆角半径
 *
 *  @param radius 圆角半径
 */
- (void)cornerRadius:(CGFloat)radius;

/**
 *  同时设定 圆角半径 描边宽度 描边颜色
 *
 *  @param radius      圆角半径
 *  @param borderWidth 描边宽度
 *  @param borderColor 描边颜色
 */
- (void)cornerRadius:(CGFloat)radius borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

@end

#pragma mark - UIScrollView

@interface UIScrollView (Halo)

@property (nonatomic, assign) CGFloat hl_insetTop;
@property (nonatomic, assign) CGFloat hl_insetBottom;
@property (nonatomic, assign) CGFloat hl_indicatorTop;
@property (nonatomic, assign) CGFloat hl_indicatorBottom;

@property (nonatomic, assign) CGFloat hl_offsetX;
@property (nonatomic, assign) CGFloat hl_offsetY;

@end

#pragma mark - UITableView

@interface UITableView (Halo)

/**
 *  默认使用 class 名作为 reuseIdentifier
 *
 *  @param cellClass 要注册的 Cell 类型
 */
- (void)hl_registerCellClass:(Class)cellClass;

@end

#pragma mark - UITableViewCell

@interface UITableViewCell (Halo)

+ (NSString *)hl_reuseIdentifier;

- (instancetype)selectionStyle:(UITableViewCellSelectionStyle)style;

@end

@interface UITableViewValue1Cell : UITableViewCell

@end

#pragma mark - UICollectionView

@interface UICollectionView (Halo)

- (void)hl_registerCellClass:(Class)cellClass;

@end

#pragma mark - UICollectionViewCell

@interface UICollectionViewCell (Halo)

+ (NSString *)hl_reuseIdentifier;

@end

#pragma mark - UINavigatoinController

@interface UINavigationController (Halo)

/**
*  使用纯色填充 NavigationBar
*
*  @param color       NavigationBar 背景颜色
*  @param tintColor   NavigationBar 标题颜色
*  @param shadowColor NavigationBar 下边分割线颜色
*/
- (void)barUseColor:(UIColor *)color tintColor:(UIColor *)tintColor shadowColor:(UIColor *)shadowColor;

@end

#pragma mark - UIColor

/**
 *  use hexstring like @"FFFFFF" (or @"#FFFFFF") to create a UIColor object
 */
UIColor *HEXStr(NSString *hexString);

/**
 *  use hexValue like 0xFFFFFF to create a UIColor object
 */
UIColor *HEX(NSUInteger hex);


/**
 RGB

 @param r 0~255
 @param g 0~255
 @param b 0~255
 */
UIColor *RGB(CGFloat r, CGFloat g, CGFloat b);

/**
 带有 alpha 的 RGB

 @param r 0~255
 @param g 0~255
 @param b 0~255
 @param a 0~1
 */
UIColor *RGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a);

UIColor *ColorWithHexValueA(NSUInteger hexValue, CGFloat a);
