; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.llnode = type { i32, %struct.llnode*, %struct.llnode* }

@.str = private unnamed_addr constant [4 x i8] c"seq\00", align 1
@.str.1 = private unnamed_addr constant [52 x i8] c"/u1/dtompkins/.seashell/projects/_A9/q2a/sequence.c\00", align 1
@__PRETTY_FUNCTION__.sequence_destroy = private unnamed_addr constant [41 x i8] c"void sequence_destroy(struct sequence *)\00", align 1
@__PRETTY_FUNCTION__.sequence_length = private unnamed_addr constant [45 x i8] c"int sequence_length(const struct sequence *)\00", align 1
@__PRETTY_FUNCTION__.sequence_item_at = private unnamed_addr constant [51 x i8] c"int sequence_item_at(const struct sequence *, int)\00", align 1
@.str.2 = private unnamed_addr constant [9 x i8] c"pos >= 0\00", align 1
@.str.3 = private unnamed_addr constant [27 x i8] c"pos < sequence_length(seq)\00", align 1
@__PRETTY_FUNCTION__.sequence_insert_front = private unnamed_addr constant [51 x i8] c"void sequence_insert_front(struct sequence *, int)\00", align 1
@__PRETTY_FUNCTION__.sequence_insert_back = private unnamed_addr constant [50 x i8] c"void sequence_insert_back(struct sequence *, int)\00", align 1
@__PRETTY_FUNCTION__.sequence_insert_at = private unnamed_addr constant [53 x i8] c"void sequence_insert_at(struct sequence *, int, int)\00", align 1
@.str.4 = private unnamed_addr constant [28 x i8] c"pos <= sequence_length(seq)\00", align 1
@__PRETTY_FUNCTION__.sequence_remove_front = private unnamed_addr constant [45 x i8] c"int sequence_remove_front(struct sequence *)\00", align 1
@.str.5 = private unnamed_addr constant [25 x i8] c"0 < sequence_length(seq)\00", align 1
@__PRETTY_FUNCTION__.sequence_remove_back = private unnamed_addr constant [44 x i8] c"int sequence_remove_back(struct sequence *)\00", align 1
@__PRETTY_FUNCTION__.sequence_remove_at = private unnamed_addr constant [47 x i8] c"int sequence_remove_at(struct sequence *, int)\00", align 1
@__PRETTY_FUNCTION__.sequence_print = private unnamed_addr constant [45 x i8] c"void sequence_print(const struct sequence *)\00", align 1
@.str.6 = private unnamed_addr constant [9 x i8] c"[empty]\0A\00", align 1
@.str.7 = private unnamed_addr constant [2 x i8] c"[\00", align 1
@.str.8 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.9 = private unnamed_addr constant [2 x i8] c",\00", align 1
@.str.10 = private unnamed_addr constant [3 x i8] c"]\0A\00", align 1
@__PRETTY_FUNCTION__.sequence_print_reverse = private unnamed_addr constant [53 x i8] c"void sequence_print_reverse(const struct sequence *)\00", align 1

; Function Attrs: noinline nounwind optnone
define %struct.llnode* @sequence_create() #0 {
entry:
  %seq = alloca %struct.llnode*, align 8
  %call = call noalias i8* @malloc(i64 24) #4
  %0 = bitcast i8* %call to %struct.llnode*
  store %struct.llnode* %0, %struct.llnode** %seq, align 8
  %1 = load %struct.llnode*, %struct.llnode** %seq, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %1, i32 0, i32 0
  store i32 0, i32* %length, align 8
  %2 = load %struct.llnode*, %struct.llnode** %seq, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %2, i32 0, i32 1
  store %struct.llnode* null, %struct.llnode** %front, align 8
  %3 = load %struct.llnode*, %struct.llnode** %seq, align 8
  %back = getelementptr inbounds %struct.llnode, %struct.llnode* %3, i32 0, i32 2
  store %struct.llnode* null, %struct.llnode** %back, align 8
  %4 = load %struct.llnode*, %struct.llnode** %seq, align 8
  ret %struct.llnode* %4
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: noinline nounwind optnone
define void @sequence_destroy(%struct.llnode* %seq) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 33, i8* getelementptr inbounds ([41 x i8], [41 x i8]* @__PRETTY_FUNCTION__.sequence_destroy, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %1, i32 0, i32 1
  %2 = load %struct.llnode*, %struct.llnode** %front, align 8
  call void @node_destroy(%struct.llnode* %2)
  %3 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %4 = bitcast %struct.llnode* %3 to i8*
  call void @free(i8* %4) #4
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: noinline nounwind optnone
define internal void @node_destroy(%struct.llnode* %node) #0 {
entry:
  %node.addr = alloca %struct.llnode*, align 8
  store %struct.llnode* %node, %struct.llnode** %node.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %node.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load %struct.llnode*, %struct.llnode** %node.addr, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %1, i32 0, i32 2
  %2 = load %struct.llnode*, %struct.llnode** %next, align 8
  call void @node_destroy(%struct.llnode* %2)
  %3 = load %struct.llnode*, %struct.llnode** %node.addr, align 8
  %4 = bitcast %struct.llnode* %3 to i8*
  call void @free(i8* %4) #4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  ret void
}

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: noinline nounwind optnone
define i32 @sequence_length(%struct.llnode* %seq) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 39, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.sequence_length, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %1, i32 0, i32 0
  %2 = load i32, i32* %length, align 8
  ret i32 %2
}

; Function Attrs: noinline nounwind optnone
define i32 @sequence_item_at(%struct.llnode* %seq, i32 %pos) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %pos.addr = alloca i32, align 4
  %node = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  store i32 %pos, i32* %pos.addr, align 4
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 44, i8* getelementptr inbounds ([51 x i8], [51 x i8]* @__PRETTY_FUNCTION__.sequence_item_at, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load i32, i32* %pos.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %if.then1, label %if.else2

if.then1:                                         ; preds = %if.end
  br label %if.end3

if.else2:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 45, i8* getelementptr inbounds ([51 x i8], [51 x i8]* @__PRETTY_FUNCTION__.sequence_item_at, i32 0, i32 0)) #5
  unreachable

if.end3:                                          ; preds = %if.then1
  %2 = load i32, i32* %pos.addr, align 4
  %3 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call = call i32 @sequence_length(%struct.llnode* %3)
  %cmp4 = icmp slt i32 %2, %call
  br i1 %cmp4, label %if.then5, label %if.else6

if.then5:                                         ; preds = %if.end3
  br label %if.end7

if.else6:                                         ; preds = %if.end3
  call void @__assert_fail(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 46, i8* getelementptr inbounds ([51 x i8], [51 x i8]* @__PRETTY_FUNCTION__.sequence_item_at, i32 0, i32 0)) #5
  unreachable

if.end7:                                          ; preds = %if.then5
  %4 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 1
  %5 = load %struct.llnode*, %struct.llnode** %front, align 8
  store %struct.llnode* %5, %struct.llnode** %node, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end7
  %6 = load i32, i32* %pos.addr, align 4
  %tobool8 = icmp ne i32 %6, 0
  br i1 %tobool8, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %7 = load %struct.llnode*, %struct.llnode** %node, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %7, i32 0, i32 2
  %8 = load %struct.llnode*, %struct.llnode** %next, align 8
  store %struct.llnode* %8, %struct.llnode** %node, align 8
  %9 = load i32, i32* %pos.addr, align 4
  %dec = add nsw i32 %9, -1
  store i32 %dec, i32* %pos.addr, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %10 = load %struct.llnode*, %struct.llnode** %node, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %10, i32 0, i32 0
  %11 = load i32, i32* %item, align 8
  ret i32 %11
}

; Function Attrs: noinline nounwind optnone
define void @sequence_insert_front(%struct.llnode* %seq, i32 %val) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %val.addr = alloca i32, align 4
  %n = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  store i32 %val, i32* %val.addr, align 4
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 56, i8* getelementptr inbounds ([51 x i8], [51 x i8]* @__PRETTY_FUNCTION__.sequence_insert_front, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %call = call noalias i8* @malloc(i64 24) #4
  %1 = bitcast i8* %call to %struct.llnode*
  store %struct.llnode* %1, %struct.llnode** %n, align 8
  %2 = load i32, i32* %val.addr, align 4
  %3 = load %struct.llnode*, %struct.llnode** %n, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %3, i32 0, i32 0
  store i32 %2, i32* %item, align 8
  %4 = load %struct.llnode*, %struct.llnode** %n, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 1
  store %struct.llnode* null, %struct.llnode** %prev, align 8
  %5 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %5, i32 0, i32 1
  %6 = load %struct.llnode*, %struct.llnode** %front, align 8
  %7 = load %struct.llnode*, %struct.llnode** %n, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %7, i32 0, i32 2
  store %struct.llnode* %6, %struct.llnode** %next, align 8
  %8 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front1 = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 1
  %9 = load %struct.llnode*, %struct.llnode** %front1, align 8
  %tobool2 = icmp ne %struct.llnode* %9, null
  br i1 %tobool2, label %if.then3, label %if.else6

if.then3:                                         ; preds = %if.end
  %10 = load %struct.llnode*, %struct.llnode** %n, align 8
  %11 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front4 = getelementptr inbounds %struct.llnode, %struct.llnode* %11, i32 0, i32 1
  %12 = load %struct.llnode*, %struct.llnode** %front4, align 8
  %prev5 = getelementptr inbounds %struct.llnode, %struct.llnode* %12, i32 0, i32 1
  store %struct.llnode* %10, %struct.llnode** %prev5, align 8
  br label %if.end7

if.else6:                                         ; preds = %if.end
  %13 = load %struct.llnode*, %struct.llnode** %n, align 8
  %14 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back = getelementptr inbounds %struct.llnode, %struct.llnode* %14, i32 0, i32 2
  store %struct.llnode* %13, %struct.llnode** %back, align 8
  br label %if.end7

if.end7:                                          ; preds = %if.else6, %if.then3
  %15 = load %struct.llnode*, %struct.llnode** %n, align 8
  %16 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front8 = getelementptr inbounds %struct.llnode, %struct.llnode* %16, i32 0, i32 1
  store %struct.llnode* %15, %struct.llnode** %front8, align 8
  %17 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %17, i32 0, i32 0
  %18 = load i32, i32* %length, align 8
  %add = add nsw i32 %18, 1
  store i32 %add, i32* %length, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @sequence_insert_back(%struct.llnode* %seq, i32 %val) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %val.addr = alloca i32, align 4
  %n = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  store i32 %val, i32* %val.addr, align 4
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 71, i8* getelementptr inbounds ([50 x i8], [50 x i8]* @__PRETTY_FUNCTION__.sequence_insert_back, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %call = call noalias i8* @malloc(i64 24) #4
  %1 = bitcast i8* %call to %struct.llnode*
  store %struct.llnode* %1, %struct.llnode** %n, align 8
  %2 = load i32, i32* %val.addr, align 4
  %3 = load %struct.llnode*, %struct.llnode** %n, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %3, i32 0, i32 0
  store i32 %2, i32* %item, align 8
  %4 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 2
  %5 = load %struct.llnode*, %struct.llnode** %back, align 8
  %6 = load %struct.llnode*, %struct.llnode** %n, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %6, i32 0, i32 1
  store %struct.llnode* %5, %struct.llnode** %prev, align 8
  %7 = load %struct.llnode*, %struct.llnode** %n, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %7, i32 0, i32 2
  store %struct.llnode* null, %struct.llnode** %next, align 8
  %8 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back1 = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 2
  %9 = load %struct.llnode*, %struct.llnode** %back1, align 8
  %tobool2 = icmp ne %struct.llnode* %9, null
  br i1 %tobool2, label %if.then3, label %if.else6

if.then3:                                         ; preds = %if.end
  %10 = load %struct.llnode*, %struct.llnode** %n, align 8
  %11 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back4 = getelementptr inbounds %struct.llnode, %struct.llnode* %11, i32 0, i32 2
  %12 = load %struct.llnode*, %struct.llnode** %back4, align 8
  %next5 = getelementptr inbounds %struct.llnode, %struct.llnode* %12, i32 0, i32 2
  store %struct.llnode* %10, %struct.llnode** %next5, align 8
  br label %if.end7

if.else6:                                         ; preds = %if.end
  %13 = load %struct.llnode*, %struct.llnode** %n, align 8
  %14 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %14, i32 0, i32 1
  store %struct.llnode* %13, %struct.llnode** %front, align 8
  br label %if.end7

if.end7:                                          ; preds = %if.else6, %if.then3
  %15 = load %struct.llnode*, %struct.llnode** %n, align 8
  %16 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back8 = getelementptr inbounds %struct.llnode, %struct.llnode* %16, i32 0, i32 2
  store %struct.llnode* %15, %struct.llnode** %back8, align 8
  %17 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %17, i32 0, i32 0
  %18 = load i32, i32* %length, align 8
  %add = add nsw i32 %18, 1
  store i32 %add, i32* %length, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @sequence_insert_at(%struct.llnode* %seq, i32 %pos, i32 %val) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %pos.addr = alloca i32, align 4
  %val.addr = alloca i32, align 4
  %prevnode = alloca %struct.llnode*, align 8
  %n = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  store i32 %pos, i32* %pos.addr, align 4
  store i32 %val, i32* %val.addr, align 4
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 86, i8* getelementptr inbounds ([53 x i8], [53 x i8]* @__PRETTY_FUNCTION__.sequence_insert_at, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load i32, i32* %pos.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %if.then1, label %if.else2

if.then1:                                         ; preds = %if.end
  br label %if.end3

if.else2:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 87, i8* getelementptr inbounds ([53 x i8], [53 x i8]* @__PRETTY_FUNCTION__.sequence_insert_at, i32 0, i32 0)) #5
  unreachable

if.end3:                                          ; preds = %if.then1
  %2 = load i32, i32* %pos.addr, align 4
  %3 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call = call i32 @sequence_length(%struct.llnode* %3)
  %cmp4 = icmp sle i32 %2, %call
  br i1 %cmp4, label %if.then5, label %if.else6

if.then5:                                         ; preds = %if.end3
  br label %if.end7

if.else6:                                         ; preds = %if.end3
  call void @__assert_fail(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @.str.4, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 88, i8* getelementptr inbounds ([53 x i8], [53 x i8]* @__PRETTY_FUNCTION__.sequence_insert_at, i32 0, i32 0)) #5
  unreachable

if.end7:                                          ; preds = %if.then5
  %4 = load i32, i32* %pos.addr, align 4
  %cmp8 = icmp eq i32 %4, 0
  br i1 %cmp8, label %if.then9, label %if.else10

if.then9:                                         ; preds = %if.end7
  %5 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %6 = load i32, i32* %val.addr, align 4
  call void @sequence_insert_front(%struct.llnode* %5, i32 %6)
  br label %if.end23

if.else10:                                        ; preds = %if.end7
  %7 = load i32, i32* %pos.addr, align 4
  %8 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call11 = call i32 @sequence_length(%struct.llnode* %8)
  %cmp12 = icmp eq i32 %7, %call11
  br i1 %cmp12, label %if.then13, label %if.else14

if.then13:                                        ; preds = %if.else10
  %9 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %10 = load i32, i32* %val.addr, align 4
  call void @sequence_insert_back(%struct.llnode* %9, i32 %10)
  br label %if.end22

if.else14:                                        ; preds = %if.else10
  %11 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %11, i32 0, i32 1
  %12 = load %struct.llnode*, %struct.llnode** %front, align 8
  store %struct.llnode* %12, %struct.llnode** %prevnode, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.else14
  %13 = load i32, i32* %pos.addr, align 4
  %cmp15 = icmp sgt i32 %13, 1
  br i1 %cmp15, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %14 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %14, i32 0, i32 2
  %15 = load %struct.llnode*, %struct.llnode** %next, align 8
  store %struct.llnode* %15, %struct.llnode** %prevnode, align 8
  %16 = load i32, i32* %pos.addr, align 4
  %dec = add nsw i32 %16, -1
  store i32 %dec, i32* %pos.addr, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %call16 = call noalias i8* @malloc(i64 24) #4
  %17 = bitcast i8* %call16 to %struct.llnode*
  store %struct.llnode* %17, %struct.llnode** %n, align 8
  %18 = load i32, i32* %val.addr, align 4
  %19 = load %struct.llnode*, %struct.llnode** %n, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %19, i32 0, i32 0
  store i32 %18, i32* %item, align 8
  %20 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %21 = load %struct.llnode*, %struct.llnode** %n, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %21, i32 0, i32 1
  store %struct.llnode* %20, %struct.llnode** %prev, align 8
  %22 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next17 = getelementptr inbounds %struct.llnode, %struct.llnode* %22, i32 0, i32 2
  %23 = load %struct.llnode*, %struct.llnode** %next17, align 8
  %24 = load %struct.llnode*, %struct.llnode** %n, align 8
  %next18 = getelementptr inbounds %struct.llnode, %struct.llnode* %24, i32 0, i32 2
  store %struct.llnode* %23, %struct.llnode** %next18, align 8
  %25 = load %struct.llnode*, %struct.llnode** %n, align 8
  %26 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next19 = getelementptr inbounds %struct.llnode, %struct.llnode* %26, i32 0, i32 2
  %27 = load %struct.llnode*, %struct.llnode** %next19, align 8
  %prev20 = getelementptr inbounds %struct.llnode, %struct.llnode* %27, i32 0, i32 1
  store %struct.llnode* %25, %struct.llnode** %prev20, align 8
  %28 = load %struct.llnode*, %struct.llnode** %n, align 8
  %29 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next21 = getelementptr inbounds %struct.llnode, %struct.llnode* %29, i32 0, i32 2
  store %struct.llnode* %28, %struct.llnode** %next21, align 8
  %30 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %30, i32 0, i32 0
  %31 = load i32, i32* %length, align 8
  %add = add nsw i32 %31, 1
  store i32 %add, i32* %length, align 8
  br label %if.end22

if.end22:                                         ; preds = %while.end, %if.then13
  br label %if.end23

if.end23:                                         ; preds = %if.end22, %if.then9
  ret void
}

; Function Attrs: noinline nounwind optnone
define i32 @sequence_remove_front(%struct.llnode* %seq) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %backup = alloca %struct.llnode*, align 8
  %ret = alloca i32, align 4
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 110, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.sequence_remove_front, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call = call i32 @sequence_length(%struct.llnode* %1)
  %cmp = icmp slt i32 0, %call
  br i1 %cmp, label %if.then1, label %if.else2

if.then1:                                         ; preds = %if.end
  br label %if.end3

if.else2:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str.5, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 111, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.sequence_remove_front, i32 0, i32 0)) #5
  unreachable

if.end3:                                          ; preds = %if.then1
  %2 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %2, i32 0, i32 1
  %3 = load %struct.llnode*, %struct.llnode** %front, align 8
  store %struct.llnode* %3, %struct.llnode** %backup, align 8
  %4 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front4 = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 1
  %5 = load %struct.llnode*, %struct.llnode** %front4, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %5, i32 0, i32 2
  %6 = load %struct.llnode*, %struct.llnode** %next, align 8
  %7 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front5 = getelementptr inbounds %struct.llnode, %struct.llnode* %7, i32 0, i32 1
  store %struct.llnode* %6, %struct.llnode** %front5, align 8
  %8 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front6 = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 1
  %9 = load %struct.llnode*, %struct.llnode** %front6, align 8
  %tobool7 = icmp ne %struct.llnode* %9, null
  br i1 %tobool7, label %if.then8, label %if.else10

if.then8:                                         ; preds = %if.end3
  %10 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front9 = getelementptr inbounds %struct.llnode, %struct.llnode* %10, i32 0, i32 1
  %11 = load %struct.llnode*, %struct.llnode** %front9, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %11, i32 0, i32 1
  store %struct.llnode* null, %struct.llnode** %prev, align 8
  br label %if.end11

if.else10:                                        ; preds = %if.end3
  %12 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back = getelementptr inbounds %struct.llnode, %struct.llnode* %12, i32 0, i32 2
  store %struct.llnode* null, %struct.llnode** %back, align 8
  br label %if.end11

if.end11:                                         ; preds = %if.else10, %if.then8
  %13 = load %struct.llnode*, %struct.llnode** %backup, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %13, i32 0, i32 0
  %14 = load i32, i32* %item, align 8
  store i32 %14, i32* %ret, align 4
  %15 = load %struct.llnode*, %struct.llnode** %backup, align 8
  %16 = bitcast %struct.llnode* %15 to i8*
  call void @free(i8* %16) #4
  %17 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %17, i32 0, i32 0
  %18 = load i32, i32* %length, align 8
  %sub = sub nsw i32 %18, 1
  store i32 %sub, i32* %length, align 8
  %19 = load i32, i32* %ret, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone
define i32 @sequence_remove_back(%struct.llnode* %seq) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %backup = alloca %struct.llnode*, align 8
  %ret = alloca i32, align 4
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 126, i8* getelementptr inbounds ([44 x i8], [44 x i8]* @__PRETTY_FUNCTION__.sequence_remove_back, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call = call i32 @sequence_length(%struct.llnode* %1)
  %cmp = icmp slt i32 0, %call
  br i1 %cmp, label %if.then1, label %if.else2

if.then1:                                         ; preds = %if.end
  br label %if.end3

if.else2:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str.5, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 127, i8* getelementptr inbounds ([44 x i8], [44 x i8]* @__PRETTY_FUNCTION__.sequence_remove_back, i32 0, i32 0)) #5
  unreachable

if.end3:                                          ; preds = %if.then1
  %2 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back = getelementptr inbounds %struct.llnode, %struct.llnode* %2, i32 0, i32 2
  %3 = load %struct.llnode*, %struct.llnode** %back, align 8
  store %struct.llnode* %3, %struct.llnode** %backup, align 8
  %4 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back4 = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 2
  %5 = load %struct.llnode*, %struct.llnode** %back4, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %5, i32 0, i32 1
  %6 = load %struct.llnode*, %struct.llnode** %prev, align 8
  %7 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back5 = getelementptr inbounds %struct.llnode, %struct.llnode* %7, i32 0, i32 2
  store %struct.llnode* %6, %struct.llnode** %back5, align 8
  %8 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back6 = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 2
  %9 = load %struct.llnode*, %struct.llnode** %back6, align 8
  %tobool7 = icmp ne %struct.llnode* %9, null
  br i1 %tobool7, label %if.then8, label %if.else10

if.then8:                                         ; preds = %if.end3
  %10 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back9 = getelementptr inbounds %struct.llnode, %struct.llnode* %10, i32 0, i32 2
  %11 = load %struct.llnode*, %struct.llnode** %back9, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %11, i32 0, i32 2
  store %struct.llnode* null, %struct.llnode** %next, align 8
  br label %if.end11

if.else10:                                        ; preds = %if.end3
  %12 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %12, i32 0, i32 1
  store %struct.llnode* null, %struct.llnode** %front, align 8
  br label %if.end11

if.end11:                                         ; preds = %if.else10, %if.then8
  %13 = load %struct.llnode*, %struct.llnode** %backup, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %13, i32 0, i32 0
  %14 = load i32, i32* %item, align 8
  store i32 %14, i32* %ret, align 4
  %15 = load %struct.llnode*, %struct.llnode** %backup, align 8
  %16 = bitcast %struct.llnode* %15 to i8*
  call void @free(i8* %16) #4
  %17 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %17, i32 0, i32 0
  %18 = load i32, i32* %length, align 8
  %sub = sub nsw i32 %18, 1
  store i32 %sub, i32* %length, align 8
  %19 = load i32, i32* %ret, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone
define i32 @sequence_remove_at(%struct.llnode* %seq, i32 %pos) #0 {
entry:
  %retval = alloca i32, align 4
  %seq.addr = alloca %struct.llnode*, align 8
  %pos.addr = alloca i32, align 4
  %prevnode = alloca %struct.llnode*, align 8
  %backup = alloca %struct.llnode*, align 8
  %ret = alloca i32, align 4
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  store i32 %pos, i32* %pos.addr, align 4
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 142, i8* getelementptr inbounds ([47 x i8], [47 x i8]* @__PRETTY_FUNCTION__.sequence_remove_at, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load i32, i32* %pos.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %if.then1, label %if.else2

if.then1:                                         ; preds = %if.end
  br label %if.end3

if.else2:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 143, i8* getelementptr inbounds ([47 x i8], [47 x i8]* @__PRETTY_FUNCTION__.sequence_remove_at, i32 0, i32 0)) #5
  unreachable

if.end3:                                          ; preds = %if.then1
  %2 = load i32, i32* %pos.addr, align 4
  %3 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call = call i32 @sequence_length(%struct.llnode* %3)
  %cmp4 = icmp slt i32 %2, %call
  br i1 %cmp4, label %if.then5, label %if.else6

if.then5:                                         ; preds = %if.end3
  br label %if.end7

if.else6:                                         ; preds = %if.end3
  call void @__assert_fail(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 144, i8* getelementptr inbounds ([47 x i8], [47 x i8]* @__PRETTY_FUNCTION__.sequence_remove_at, i32 0, i32 0)) #5
  unreachable

if.end7:                                          ; preds = %if.then5
  %4 = load i32, i32* %pos.addr, align 4
  %cmp8 = icmp eq i32 %4, 0
  br i1 %cmp8, label %if.then9, label %if.end11

if.then9:                                         ; preds = %if.end7
  %5 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call10 = call i32 @sequence_remove_front(%struct.llnode* %5)
  store i32 %call10, i32* %retval, align 4
  br label %return

if.end11:                                         ; preds = %if.end7
  %6 = load i32, i32* %pos.addr, align 4
  %7 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call12 = call i32 @sequence_length(%struct.llnode* %7)
  %sub = sub nsw i32 %call12, 1
  %cmp13 = icmp eq i32 %6, %sub
  br i1 %cmp13, label %if.then14, label %if.end16

if.then14:                                        ; preds = %if.end11
  %8 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %call15 = call i32 @sequence_remove_back(%struct.llnode* %8)
  store i32 %call15, i32* %retval, align 4
  br label %return

if.end16:                                         ; preds = %if.end11
  %9 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %9, i32 0, i32 1
  %10 = load %struct.llnode*, %struct.llnode** %front, align 8
  store %struct.llnode* %10, %struct.llnode** %prevnode, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end16
  %11 = load i32, i32* %pos.addr, align 4
  %cmp17 = icmp sgt i32 %11, 1
  br i1 %cmp17, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %12 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %12, i32 0, i32 2
  %13 = load %struct.llnode*, %struct.llnode** %next, align 8
  store %struct.llnode* %13, %struct.llnode** %prevnode, align 8
  %14 = load i32, i32* %pos.addr, align 4
  %dec = add nsw i32 %14, -1
  store i32 %dec, i32* %pos.addr, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %15 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next18 = getelementptr inbounds %struct.llnode, %struct.llnode* %15, i32 0, i32 2
  %16 = load %struct.llnode*, %struct.llnode** %next18, align 8
  store %struct.llnode* %16, %struct.llnode** %backup, align 8
  %17 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next19 = getelementptr inbounds %struct.llnode, %struct.llnode* %17, i32 0, i32 2
  %18 = load %struct.llnode*, %struct.llnode** %next19, align 8
  %next20 = getelementptr inbounds %struct.llnode, %struct.llnode* %18, i32 0, i32 2
  %19 = load %struct.llnode*, %struct.llnode** %next20, align 8
  %20 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next21 = getelementptr inbounds %struct.llnode, %struct.llnode* %20, i32 0, i32 2
  store %struct.llnode* %19, %struct.llnode** %next21, align 8
  %21 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %22 = load %struct.llnode*, %struct.llnode** %prevnode, align 8
  %next22 = getelementptr inbounds %struct.llnode, %struct.llnode* %22, i32 0, i32 2
  %23 = load %struct.llnode*, %struct.llnode** %next22, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %23, i32 0, i32 1
  store %struct.llnode* %21, %struct.llnode** %prev, align 8
  %24 = load %struct.llnode*, %struct.llnode** %backup, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %24, i32 0, i32 0
  %25 = load i32, i32* %item, align 8
  store i32 %25, i32* %ret, align 4
  %26 = load %struct.llnode*, %struct.llnode** %backup, align 8
  %27 = bitcast %struct.llnode* %26 to i8*
  call void @free(i8* %27) #4
  %28 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %28, i32 0, i32 0
  %29 = load i32, i32* %length, align 8
  %sub23 = sub nsw i32 %29, 1
  store i32 %sub23, i32* %length, align 8
  %30 = load i32, i32* %ret, align 4
  store i32 %30, i32* %retval, align 4
  br label %return

return:                                           ; preds = %while.end, %if.then14, %if.then9
  %31 = load i32, i32* %retval, align 4
  ret i32 %31
}

; Function Attrs: noinline nounwind optnone
define void @sequence_print(%struct.llnode* %seq) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %node = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 166, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.sequence_print, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %1, i32 0, i32 0
  %2 = load i32, i32* %length, align 8
  %cmp = icmp eq i32 %2, 0
  br i1 %cmp, label %if.then1, label %if.end2

if.then1:                                         ; preds = %if.end
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.6, i32 0, i32 0))
  br label %return

if.end2:                                          ; preds = %if.end
  %call3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.7, i32 0, i32 0))
  %3 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %front = getelementptr inbounds %struct.llnode, %struct.llnode* %3, i32 0, i32 1
  %4 = load %struct.llnode*, %struct.llnode** %front, align 8
  store %struct.llnode* %4, %struct.llnode** %node, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end9, %if.end2
  %5 = load %struct.llnode*, %struct.llnode** %node, align 8
  %tobool4 = icmp ne %struct.llnode* %5, null
  br i1 %tobool4, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %6 = load %struct.llnode*, %struct.llnode** %node, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %6, i32 0, i32 0
  %7 = load i32, i32* %item, align 8
  %call5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.8, i32 0, i32 0), i32 %7)
  %8 = load %struct.llnode*, %struct.llnode** %node, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 2
  %9 = load %struct.llnode*, %struct.llnode** %next, align 8
  store %struct.llnode* %9, %struct.llnode** %node, align 8
  %10 = load %struct.llnode*, %struct.llnode** %node, align 8
  %tobool6 = icmp ne %struct.llnode* %10, null
  br i1 %tobool6, label %if.then7, label %if.end9

if.then7:                                         ; preds = %while.body
  %call8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
  br label %if.end9

if.end9:                                          ; preds = %if.then7, %while.body
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.10, i32 0, i32 0))
  br label %return

return:                                           ; preds = %while.end, %if.then1
  ret void
}

declare i32 @printf(i8*, ...) #3

; Function Attrs: noinline nounwind optnone
define void @sequence_print_reverse(%struct.llnode* %seq) #0 {
entry:
  %seq.addr = alloca %struct.llnode*, align 8
  %node = alloca %struct.llnode*, align 8
  store %struct.llnode* %seq, %struct.llnode** %seq.addr, align 8
  %0 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %tobool = icmp ne %struct.llnode* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 182, i8* getelementptr inbounds ([53 x i8], [53 x i8]* @__PRETTY_FUNCTION__.sequence_print_reverse, i32 0, i32 0)) #5
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %length = getelementptr inbounds %struct.llnode, %struct.llnode* %1, i32 0, i32 0
  %2 = load i32, i32* %length, align 8
  %cmp = icmp eq i32 %2, 0
  br i1 %cmp, label %if.then1, label %if.end2

if.then1:                                         ; preds = %if.end
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.6, i32 0, i32 0))
  br label %return

if.end2:                                          ; preds = %if.end
  %call3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.7, i32 0, i32 0))
  %3 = load %struct.llnode*, %struct.llnode** %seq.addr, align 8
  %back = getelementptr inbounds %struct.llnode, %struct.llnode* %3, i32 0, i32 2
  %4 = load %struct.llnode*, %struct.llnode** %back, align 8
  store %struct.llnode* %4, %struct.llnode** %node, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end9, %if.end2
  %5 = load %struct.llnode*, %struct.llnode** %node, align 8
  %tobool4 = icmp ne %struct.llnode* %5, null
  br i1 %tobool4, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %6 = load %struct.llnode*, %struct.llnode** %node, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %6, i32 0, i32 0
  %7 = load i32, i32* %item, align 8
  %call5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.8, i32 0, i32 0), i32 %7)
  %8 = load %struct.llnode*, %struct.llnode** %node, align 8
  %prev = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 1
  %9 = load %struct.llnode*, %struct.llnode** %prev, align 8
  store %struct.llnode* %9, %struct.llnode** %node, align 8
  %10 = load %struct.llnode*, %struct.llnode** %node, align 8
  %tobool6 = icmp ne %struct.llnode* %10, null
  br i1 %tobool6, label %if.then7, label %if.end9

if.then7:                                         ; preds = %while.body
  %call8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.9, i32 0, i32 0))
  br label %if.end9

if.end9:                                          ; preds = %if.then7, %while.body
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.10, i32 0, i32 0))
  br label %return

return:                                           ; preds = %while.end, %if.then1
  ret void
}

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 7.1.0 (https://github.com/llvm-mirror/clang.git 4519e2637fcc4bf6e3049a0a80e6a5e7b97667cb) (https://github.com/llvm-mirror/llvm.git dd3329aeb25d87d4ac6429c0af220f92e1ba5f26)"}
!1 = !{i32 1, !"wchar_size", i32 4}
