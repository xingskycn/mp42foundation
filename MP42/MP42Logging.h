//
//  MP42Logger.h
//  MP42Foundation
//
//  Created by Damiano Galassi on 26/10/14.
//  Copyright (c) 2014 Damiano Galassi. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MP42Logging <NSObject>

- (void)writeToLog:(NSString *)string;

@end
