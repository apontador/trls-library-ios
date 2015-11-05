//
//  TRLSTrackerContainer.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 23/04/15.
//  Copyright (c) 2015 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TRLSTrackerContainer : NSObject <NSCoding, NSCopying>

- (id)initWithAccuracy:(double)accuracy clientId:(NSString *)clientId eventDate:(NSDate *)eventDate installationId:(NSString *)installationId lat:(double)lat lon:(double)lon speed:(double)speed userId:(NSString *)userId externalId:(NSString *)externalId;

@property (nonatomic, strong) NSNumber *accuracy;
@property (nonatomic, strong) NSString *clientId;
@property (nonatomic, strong) NSString *eventDate;
@property (nonatomic, strong) NSString *installationId;
@property (nonatomic, strong) NSNumber *lat;
@property (nonatomic, strong) NSNumber *lon;
@property (nonatomic, strong) NSNumber *speed;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *externalId;

@end
