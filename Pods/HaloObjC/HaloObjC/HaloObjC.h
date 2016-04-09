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

#pragma mark - Measure

/**
 *  测量某段代码的执行时间
 *  你不用考虑 block 执行的线程
 *
 *  @param ^CodeWaitingForMeasure 你想测量的代码
 */
void Measure(void(^CodeWaitingForMeasure)());

#pragma mark - GCD

void Async(void(^noUITask)());

void AsyncFinish(void(^noUITask)(), void(^UITask)());

void Last(void(^UITask)());

void After(float second, void(^UITask)());

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
 *  开始服务
 *  已经不用主动调用该方法了
 */
+ (void)server DEPRECATED_ATTRIBUTE;

/**
 *  是否开启 Log（也就是 ccLog），默认值是 YES
 */
+ (void)logEnable:(BOOL)enable;

@end

#pragma mark - UIView

/// 相当于 CGRectMake
CGRect RM(CGFloat x, CGFloat y, CGFloat width, CGFloat height);

/// 创建一个水平居中（相对于屏幕）的 CGRect 值
CGRect CM(CGFloat y, CGFloat width, CGFloat height);

@interface UIView (Halo)

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

@end

@interface UITableViewValue1Cell : UITableViewCell

@end

#pragma mark - UICollectionViewCell

@interface UICollectionViewCell (Halo)

+ (NSString *)hl_reuseIdentifier;

@end

#pragma mark - UIColor

UIColor *ColorWithRGB(CGFloat r, CGFloat g, CGFloat b);
UIColor *ColorWithRGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a);

/**
 *  use hexValue like 0xFFFFFF to create a UIColor object
 */
UIColor *ColorWithHexValue(NSUInteger hexValue);
UIColor *ColorWithHexValueA(NSUInteger hexValue, CGFloat a);

/**
 *  use hexValue like @"FFFFFF" (or @"#FFFFFF") to create a UIColor object
 */
UIColor *HEX(NSString *hexString);

UIColor *RGB(CGFloat r, CGFloat g, CGFloat b);

/**
 *  带有 alpha 的 RGB
 *  @param a 0~1.0
 */
UIColor *RGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a);


