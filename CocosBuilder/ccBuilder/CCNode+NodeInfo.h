//
//  CCNode+NodeInfo.h
//  CocosBuilder
//
//  Created by Viktor Lidholt on 5/31/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "cocos2d.h"

@class PlugInNode;
@class SequencerNodeProperty;
@class SequencerKeyframe;

@interface CCNode (NodeInfo)

@property (nonatomic,assign) BOOL seqExpanded;
@property (nonatomic,readonly) PlugInNode* plugIn;

- (id) extraPropForKey:(NSString*)key;
- (void) setExtraProp:(id)prop forKey:(NSString*)key;

- (id) baseValueForProperty:(NSString*)name;
- (void) setBaseValue:(id)value forProperty:(NSString*)name;

- (SequencerNodeProperty*) sequenceNodeProperty:(NSString*)name sequenceId:(int)seqId;
- (void) enableSequenceNodeProperty:(NSString*)name sequenceId:(int)seqId;

- (void) addKeyframe:(SequencerKeyframe*)keyframe forProperty:(NSString*)name atTime:(float)time sequenceId:(int)seqId;
- (void) addDefaultKeyframeForProperty:(NSString*)name atTime:(float)time sequenceId:(int)seqId;

- (void) deselectAllKeyframes;
- (void) addSelectedKeyframesToArray:(NSMutableArray*)keyframes;

- (id) valueForProperty:(NSString*)name atTime:(float)time sequenceId:(int)seqId;
- (void) updatePropertiesTime:(float)time sequenceId:(int)seqId;

- (void) deleteSequenceId:(int) seqId;

- (BOOL) deleteSelectedKeyframesForSequenceId:(int)seqId;

- (BOOL) deleteDuplicateKeyframesForSequenceId:(int)seqId;
- (void) deleteKeyframesAfterTime:(float)time sequenceId:(int)seqId;

- (id) serializeAnimatedProperties;
- (void) loadAnimatedPropertiesFromSerialization:(id)ser;

@end
