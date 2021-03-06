// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CFight.proto

package com.thanple.gs.common.nio.protocol;

public final class _CFight {
  private _CFight() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface CFightOrBuilder extends
      // @@protoc_insertion_point(interface_extends:CFight)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>required int32 fighthType = 1;</code>
     */
    boolean hasFighthType();
    /**
     * <code>required int32 fighthType = 1;</code>
     */
    int getFighthType();

    /**
     * <code>required int32 skillType = 2;</code>
     */
    boolean hasSkillType();
    /**
     * <code>required int32 skillType = 2;</code>
     */
    int getSkillType();

    /**
     * <code>required int32 fighthId = 3;</code>
     */
    boolean hasFighthId();
    /**
     * <code>required int32 fighthId = 3;</code>
     */
    int getFighthId();
  }
  /**
   * Protobuf type {@code CFight}
   */
  public static final class CFight extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:CFight)
      CFightOrBuilder {
    // Use CFight.newBuilder() to construct.
    private CFight(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private CFight(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final CFight defaultInstance;
    public static CFight getDefaultInstance() {
      return defaultInstance;
    }

    public CFight getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private CFight(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      initFields();
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 8: {
              bitField0_ |= 0x00000001;
              fighthType_ = input.readInt32();
              break;
            }
            case 16: {
              bitField0_ |= 0x00000002;
              skillType_ = input.readInt32();
              break;
            }
            case 24: {
              bitField0_ |= 0x00000004;
              fighthId_ = input.readInt32();
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e.getMessage()).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return com.thanple.gs.common.nio.protocol._CFight.internal_static_CFight_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.thanple.gs.common.nio.protocol._CFight.internal_static_CFight_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.thanple.gs.common.nio.protocol._CFight.CFight.class, com.thanple.gs.common.nio.protocol._CFight.CFight.Builder.class);
    }

    public static com.google.protobuf.Parser<CFight> PARSER =
        new com.google.protobuf.AbstractParser<CFight>() {
      public CFight parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new CFight(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<CFight> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int FIGHTHTYPE_FIELD_NUMBER = 1;
    private int fighthType_;
    /**
     * <code>required int32 fighthType = 1;</code>
     */
    public boolean hasFighthType() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>required int32 fighthType = 1;</code>
     */
    public int getFighthType() {
      return fighthType_;
    }

    public static final int SKILLTYPE_FIELD_NUMBER = 2;
    private int skillType_;
    /**
     * <code>required int32 skillType = 2;</code>
     */
    public boolean hasSkillType() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <code>required int32 skillType = 2;</code>
     */
    public int getSkillType() {
      return skillType_;
    }

    public static final int FIGHTHID_FIELD_NUMBER = 3;
    private int fighthId_;
    /**
     * <code>required int32 fighthId = 3;</code>
     */
    public boolean hasFighthId() {
      return ((bitField0_ & 0x00000004) == 0x00000004);
    }
    /**
     * <code>required int32 fighthId = 3;</code>
     */
    public int getFighthId() {
      return fighthId_;
    }

    private void initFields() {
      fighthType_ = 0;
      skillType_ = 0;
      fighthId_ = 0;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasFighthType()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasSkillType()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasFighthId()) {
        memoizedIsInitialized = 0;
        return false;
      }
      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeInt32(1, fighthType_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeInt32(2, skillType_);
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        output.writeInt32(3, fighthId_);
      }
      getUnknownFields().writeTo(output);
    }

    private int memoizedSerializedSize = -1;
    public int getSerializedSize() {
      int size = memoizedSerializedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(1, fighthType_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(2, skillType_);
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(3, fighthId_);
      }
      size += getUnknownFields().getSerializedSize();
      memoizedSerializedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    protected java.lang.Object writeReplace()
        throws java.io.ObjectStreamException {
      return super.writeReplace();
    }

    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CFight.CFight parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.thanple.gs.common.nio.protocol._CFight.CFight prototype) {
      return newBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() { return newBuilder(this); }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessage.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code CFight}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:CFight)
        com.thanple.gs.common.nio.protocol._CFight.CFightOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.thanple.gs.common.nio.protocol._CFight.internal_static_CFight_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.thanple.gs.common.nio.protocol._CFight.internal_static_CFight_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.thanple.gs.common.nio.protocol._CFight.CFight.class, com.thanple.gs.common.nio.protocol._CFight.CFight.Builder.class);
      }

      // Construct using com.thanple.gs.common.nio.protocol._CFight.CFight.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessage.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessage.alwaysUseFieldBuilders) {
        }
      }
      private static Builder create() {
        return new Builder();
      }

      public Builder clear() {
        super.clear();
        fighthType_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        skillType_ = 0;
        bitField0_ = (bitField0_ & ~0x00000002);
        fighthId_ = 0;
        bitField0_ = (bitField0_ & ~0x00000004);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.thanple.gs.common.nio.protocol._CFight.internal_static_CFight_descriptor;
      }

      public com.thanple.gs.common.nio.protocol._CFight.CFight getDefaultInstanceForType() {
        return com.thanple.gs.common.nio.protocol._CFight.CFight.getDefaultInstance();
      }

      public com.thanple.gs.common.nio.protocol._CFight.CFight build() {
        com.thanple.gs.common.nio.protocol._CFight.CFight result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.thanple.gs.common.nio.protocol._CFight.CFight buildPartial() {
        com.thanple.gs.common.nio.protocol._CFight.CFight result = new com.thanple.gs.common.nio.protocol._CFight.CFight(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.fighthType_ = fighthType_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.skillType_ = skillType_;
        if (((from_bitField0_ & 0x00000004) == 0x00000004)) {
          to_bitField0_ |= 0x00000004;
        }
        result.fighthId_ = fighthId_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.thanple.gs.common.nio.protocol._CFight.CFight) {
          return mergeFrom((com.thanple.gs.common.nio.protocol._CFight.CFight)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.thanple.gs.common.nio.protocol._CFight.CFight other) {
        if (other == com.thanple.gs.common.nio.protocol._CFight.CFight.getDefaultInstance()) return this;
        if (other.hasFighthType()) {
          setFighthType(other.getFighthType());
        }
        if (other.hasSkillType()) {
          setSkillType(other.getSkillType());
        }
        if (other.hasFighthId()) {
          setFighthId(other.getFighthId());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        if (!hasFighthType()) {
          
          return false;
        }
        if (!hasSkillType()) {
          
          return false;
        }
        if (!hasFighthId()) {
          
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.thanple.gs.common.nio.protocol._CFight.CFight parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.thanple.gs.common.nio.protocol._CFight.CFight) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int fighthType_ ;
      /**
       * <code>required int32 fighthType = 1;</code>
       */
      public boolean hasFighthType() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>required int32 fighthType = 1;</code>
       */
      public int getFighthType() {
        return fighthType_;
      }
      /**
       * <code>required int32 fighthType = 1;</code>
       */
      public Builder setFighthType(int value) {
        bitField0_ |= 0x00000001;
        fighthType_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 fighthType = 1;</code>
       */
      public Builder clearFighthType() {
        bitField0_ = (bitField0_ & ~0x00000001);
        fighthType_ = 0;
        onChanged();
        return this;
      }

      private int skillType_ ;
      /**
       * <code>required int32 skillType = 2;</code>
       */
      public boolean hasSkillType() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <code>required int32 skillType = 2;</code>
       */
      public int getSkillType() {
        return skillType_;
      }
      /**
       * <code>required int32 skillType = 2;</code>
       */
      public Builder setSkillType(int value) {
        bitField0_ |= 0x00000002;
        skillType_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 skillType = 2;</code>
       */
      public Builder clearSkillType() {
        bitField0_ = (bitField0_ & ~0x00000002);
        skillType_ = 0;
        onChanged();
        return this;
      }

      private int fighthId_ ;
      /**
       * <code>required int32 fighthId = 3;</code>
       */
      public boolean hasFighthId() {
        return ((bitField0_ & 0x00000004) == 0x00000004);
      }
      /**
       * <code>required int32 fighthId = 3;</code>
       */
      public int getFighthId() {
        return fighthId_;
      }
      /**
       * <code>required int32 fighthId = 3;</code>
       */
      public Builder setFighthId(int value) {
        bitField0_ |= 0x00000004;
        fighthId_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 fighthId = 3;</code>
       */
      public Builder clearFighthId() {
        bitField0_ = (bitField0_ & ~0x00000004);
        fighthId_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:CFight)
    }

    static {
      defaultInstance = new CFight(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:CFight)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_CFight_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_CFight_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\014CFight.proto\"A\n\006CFight\022\022\n\nfighthType\030\001" +
      " \002(\005\022\021\n\tskillType\030\002 \002(\005\022\020\n\010fighthId\030\003 \002(" +
      "\005B-\n\"com.thanple.gs.common.nio.protocolB" +
      "\007_CFight"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
    internal_static_CFight_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_CFight_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_CFight_descriptor,
        new java.lang.String[] { "FighthType", "SkillType", "FighthId", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
