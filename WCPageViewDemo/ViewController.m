//
//  ViewController.m
//  WCPageView
//
//  Created by 王策 on 16/3/19.
//  Copyright © 2016年 王策. All rights reserved.
//

#import "ViewController.h"
#import <WCPageView/WCPageView.h>
#import <HaloObjC/HaloObjC.h>

@interface ViewController () <WCPageViewDataSource, UICollectionViewDelegate>

@property (nonatomic, strong) NSArray<NSString *> *dataArray;

@end

@implementation ViewController

- (void)initData {
    self.dataArray = @[@"A", @"B", @"C", @"D"];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initData];
    
    WCPageView *pageView = [WCPageView pageViewWithFrame:CGRectMake(0, 200, ScreenWidth, 200) dataSource:self];
    pageView.infinite = NO;
    pageView.collectionView.delegate = self;
    
    [self.view addSubview:pageView];
}

#pragma mark - UICollectionViewDelegate

#pragma mark - WCPageViewDataSource

- (NSInteger)numberOfItemsInPageView:(WCPageView *)pageView {
    return self.dataArray.count;
}

- (void)pageView:(WCPageView *)pageView configCell:(UICollectionViewCell *)cell atIndex:(NSInteger)index {
    cell.backgroundColor = [UIColor colorWithRed:0.5
                                           green:((CGFloat) index / self.dataArray.count)
                                            blue:((CGFloat) index / self.dataArray.count)
                                           alpha:1];
}

- (Class)collectionViewCellClassOfPageView:(WCPageView *)pageView {
    return [UICollectionViewCell class];
}

@end

