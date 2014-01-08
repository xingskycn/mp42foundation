//
//  MP42PreviewGenerator.h
//  MP42Foundation
//
//  Created by Damiano Galassi on 08/01/14.
//  Copyright (c) 2014 Damiano Galassi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MP42PreviewGenerator : NSObject


+ (NSArray *)generatePreviewImagesFromChapters:(NSArray *)chapters andFile:(NSURL *)file;

+ (NSArray *)generatePreviewImagesQTKitFromChapters:(NSArray *)chapters andFile:(NSURL *)file;
+ (NSArray *)generatePreviewImagesAVFoundationFromChapters:(NSArray *)chapters andFile:(NSURL *)file;

@end
