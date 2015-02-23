//
//  TRLSDevice.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 12/12/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TRLSDeviceContainer : NSObject

- (id)initWithInstallationId:(NSString *)installationId clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret name:(NSString *)name phone:(NSString *)phone userId:(NSString *)userId externalId:(NSString *)externalId status:(NSString *)status deviceType:(NSString *)deviceType token:(NSString *)token;
- (BOOL)equals:(TRLSDeviceContainer *)otherDevice;

@property (nonatomic, strong) NSString *installationId;
@property (nonatomic, strong) NSString *clientId;
@property (nonatomic, strong) NSString *clientSecret;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *externalId;
@property (nonatomic, strong) NSString *status;
@property (nonatomic, strong) NSString *deviceType;
@property (nonatomic, strong) NSString *token;

@end