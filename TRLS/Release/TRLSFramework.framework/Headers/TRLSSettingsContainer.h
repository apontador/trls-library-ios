//
//  TRLSSettingsContainer.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TRLSSettingsContainer : NSObject

- (id)initWithTrackingInterval:(NSNumber *)trackingInterval minimumTrackingPositions:(NSNumber *)minimumTrackingPositions updateSettingsInterval:(NSNumber *)updateSettingsInterval updateMessageInterval:(NSNumber *)updateMessageInterval beacons:(NSArray *)beacons;

@property (nonatomic, retain) NSNumber *installationId;
@property (nonatomic, retain) NSNumber *trackingInterval;
@property (nonatomic, retain) NSNumber *minimumTrackingPositions;
@property (nonatomic, retain) NSNumber *updateSettingsInterval;
@property (nonatomic, retain) NSNumber *updateMessageInterval;
@property (nonatomic, retain) NSArray *beacons;

@end