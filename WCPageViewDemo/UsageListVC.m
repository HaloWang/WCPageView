//
//  UsageListVC.m
//  WCPageViewDemo
//
//  Created by WangCe on 16/03/2017.
//  Copyright © 2017 王策. All rights reserved.
//

#import "UsageListVC.h"
#import <HaloObjC/HaloObjC.h>

@interface UsageListVC () <UITableViewDataSource, UITableViewDelegate>

@property UITableView *list;
@property NSArray<NSDictionary<NSString *, NSString *> *> *listData;

@end

@implementation UsageListVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [HaloObjC server];
    
    self.title = @"demo list";
    
    self.list = [[[UITableView alloc] initWithFrame:ScreenBounds style:UITableViewStylePlain] addToSuperview:self.view];
    self.list.dataSource = self;
    self.list.delegate = self;
    self.list.tableFooterView = [UIView new];
    [self.list hl_registerCellClass:[UITableViewValue1Cell class]];
    
    self.listData = @[
                      @{
                          @"title":@"轮播图",
                          @"class":@"CarouselVC"
                          },
                      @{
                          @"title":@"分页列表",
                          @"class":@""
                          },
                    ];
    
}

#pragma mark - UITableViewDataSource & UITableViewDelegate

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _listData.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewValue1Cell *cell = [tableView dequeueReusableCellWithIdentifier:[UITableViewValue1Cell hl_reuseIdentifier]];
    cell.textLabel.text = _listData[indexPath.row][@"title"];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    UIViewController *vc = [NSClassFromString(_listData[indexPath.row][@"class"]) new];
    [self.navigationController pushViewController:vc animated:YES];
}

@end
