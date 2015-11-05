//
//  TRLSConnectionManager.h
//  TRLS
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TRLSConnectionManager : NSObject

typedef void (^ TRLSConnectionCallback)(NSData *responseData , long statusCode);

- (void)startRequest:(NSString *)endpointId connectionMethod:(NSString *)connectionMethod postString:(NSString *)postString contentType:(NSString *)contentType shouldAuthorize:(BOOL)shouldAuthorize connectionCallback:(TRLSConnectionCallback)connectionCallback;
- (void)uploadDevicePhoto:(NSData *)imageData connectionCallback:(TRLSConnectionCallback)connectionCallback;
//+ (NSString *)getToken;

@end