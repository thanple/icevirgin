// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SFightMonsterInfo.proto

package com.thanple.gs.common.nio.protocol;

public final class _SFightMonsterInfo {
  private _SFightMonsterInfo() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface SFightMonsterInfoOrBuilder extends
      // @@protoc_insertion_point(interface_extends:SFightMonsterInfo)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>required int32 monsterId = 1;</code>
     */
    boolean hasMonsterId();
    /**
     * <code>required int32 monsterId = 1;</code>
     */
    int getMonsterId();
  }
  /**
   * Protobuf type {@code SFightMonsterInfo}
   */
  public static final class SFightMonsterInfo extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:SFightMonsterInfo)
      SFightMonsterInfoOrBuilder {
    // Use SFightMonsterInfo.newBuilder() to construct.
    private SFightMonsterInfo(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private SFightMonsterInfo(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final SFightMonsterInfo defaultInstance;
    public static SFightMonsterInfo getDefaultInstance() {
      return defaultInstance;
    }

    public SFightMonsterInfo getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private SFightMonsterInfo(
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
              monsterId_ = input.readInt32();
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
      return com.thanple.gs.common.nio.protocol._SFightMonsterInfo.internal_static_SFightMonsterInfo_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.thanple.gs.common.nio.protocol._SFightMonsterInfo.internal_static_SFightMonsterInfo_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.class, com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.Builder.class);
    }

    public static com.google.protobuf.Parser<SFightMonsterInfo> PARSER =
        new com.google.protobuf.AbstractParser<SFightMonsterInfo>() {
      public SFightMonsterInfo parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new SFightMonsterInfo(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<SFightMonsterInfo> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int MONSTERID_FIELD_NUMBER = 1;
    private int monsterId_;
    /**
     * <code>required int32 monsterId = 1;</code>
     */
    public boolean hasMonsterId() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>required int32 monsterId = 1;</code>
     */
    public int getMonsterId() {
      return monsterId_;
    }

    private void initFields() {
      monsterId_ = 0;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasMonsterId()) {
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
        output.writeInt32(1, monsterId_);
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
          .computeInt32Size(1, monsterId_);
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

    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo prototype) {
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
     * Protobuf type {@code SFightMonsterInfo}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:SFightMonsterInfo)
        com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfoOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.thanple.gs.common.nio.protocol._SFightMonsterInfo.internal_static_SFightMonsterInfo_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.thanple.gs.common.nio.protocol._SFightMonsterInfo.internal_static_SFightMonsterInfo_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.class, com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.Builder.class);
      }

      // Construct using com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.newBuilder()
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
        monsterId_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.thanple.gs.common.nio.protocol._SFightMonsterInfo.internal_static_SFightMonsterInfo_descriptor;
      }

      public com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo getDefaultInstanceForType() {
        return com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.getDefaultInstance();
      }

      public com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo build() {
        com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo buildPartial() {
        com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo result = new com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.monsterId_ = monsterId_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo) {
          return mergeFrom((com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo other) {
        if (other == com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo.getDefaultInstance()) return this;
        if (other.hasMonsterId()) {
          setMonsterId(other.getMonsterId());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        if (!hasMonsterId()) {
          
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.thanple.gs.common.nio.protocol._SFightMonsterInfo.SFightMonsterInfo) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int monsterId_ ;
      /**
       * <code>required int32 monsterId = 1;</code>
       */
      public boolean hasMonsterId() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>required int32 monsterId = 1;</code>
       */
      public int getMonsterId() {
        return monsterId_;
      }
      /**
       * <code>required int32 monsterId = 1;</code>
       */
      public Builder setMonsterId(int value) {
        bitField0_ |= 0x00000001;
        monsterId_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 monsterId = 1;</code>
       */
      public Builder clearMonsterId() {
        bitField0_ = (bitField0_ & ~0x00000001);
        monsterId_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:SFightMonsterInfo)
    }

    static {
      defaultInstance = new SFightMonsterInfo(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:SFightMonsterInfo)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_SFightMonsterInfo_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_SFightMonsterInfo_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\027SFightMonsterInfo.proto\"&\n\021SFightMonst" +
      "erInfo\022\021\n\tmonsterId\030\001 \002(\005B8\n\"com.thanple" +
      ".gs.common.nio.protocolB\022_SFightMonsterI" +
      "nfo"
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
    internal_static_SFightMonsterInfo_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_SFightMonsterInfo_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_SFightMonsterInfo_descriptor,
        new java.lang.String[] { "MonsterId", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
