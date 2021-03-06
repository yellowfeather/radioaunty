//
//  BBCSchedule.h
//  Radio
//
//  Created by Duncan Robertson on 27/05/2010.
//  Copyright 2010 Whomwah.com. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class BBCService;
@class BBCBroadcast;

@interface BBCSchedule : NSObject {  
  NSString *serviceKey;
  NSString *outletKey;
  NSDate *date;
  
  NSArray *broadcasts;
  BBCService *service;
}


@property (nonatomic, copy) NSString *serviceKey;
@property (nonatomic, copy) NSString *outletKey;
@property (nonatomic, retain) NSArray *broadcasts;
@property (nonatomic, retain) BBCService *service;
@property (nonatomic, retain) NSDate *date;
@property (nonatomic, readonly, retain) BBCBroadcast *current_broadcast;

- (id)initUsingNetwork:(NSString *)network andOutlet:(NSString *)outlet;
- (BBCSchedule *)fetchScheduleForDate:(NSDate *)scheduleDate;
- (BBCSchedule *)fetch;
- (BBCSchedule *)refreshDateAndFetch;
- (NSURL *)constructUrl;
- (void)fetch:(NSURL *)url;
- (BBCBroadcast *)next_broadcast;
- (BBCBroadcast *)previous_broadcast;
- (NSString *)broadcastDisplayTitleForIndex:(int)index;
- (NSString *)currentBroadcastDisplayTitle;

@end
