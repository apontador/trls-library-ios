//
//  TRLSVisitsController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface TRLSVisitsController : NSObject<CLLocationManagerDelegate>

typedef void (^ TRLSVisitRequestCallback)();

@property (nonatomic, strong) TRLSVisitRequestCallback errorRequestCallback;
@property (nonatomic, strong) TRLSVisitRequestCallback sendLocationCallback;

- (void)startVisitsMonitoring;
- (void)sendErrorRequestIfNeeded:(TRLSVisitRequestCallback)callback;
- (void)getAndSendLocation:(BOOL)updatePosition checkErrorList:(BOOL)checkErrorList callback:(TRLSVisitRequestCallback)callback;

@end