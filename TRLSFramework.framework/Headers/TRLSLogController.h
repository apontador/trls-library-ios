//
//  TRLSLogController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TRLSLogController : NSObject

+ (void)consoleLog:(NSString *)message;
+ (void)saveLog:(NSString *)message;
+ (NSString *)getSavedLog;
+ (void)debugLog:(NSString *)localNotificationMessage validation:(int)validation;

@end