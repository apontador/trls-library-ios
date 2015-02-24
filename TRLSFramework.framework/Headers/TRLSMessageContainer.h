//
//  TRLSMessageContainer.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TRLSMessageContainer : NSObject

- (id)initWithMessageId:(NSString *)messageId urlScheme:(NSString *)urlScheme title:(NSString *)title text:(NSString *)text imageUrl:(NSString *)imageUrl actionButtonTitle:(NSString *)actionButtonTitle notificationTitle:(NSString *)notificationTitle notificationMessage:(NSString *)notificationMessage messageInterval:(int)messageInterval;

@property (nonatomic, retain) NSString *messageId;
@property (nonatomic, retain) NSString *urlScheme;
@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *text;
@property (nonatomic, retain) NSString *imageUrl;
@property (nonatomic, retain) NSString *actionButtonTitle;
@property (nonatomic, retain) NSString *notificationTitle;
@property (nonatomic, retain) NSString *notificationMessage;
@property (nonatomic, assign) int messageInterval;

@end