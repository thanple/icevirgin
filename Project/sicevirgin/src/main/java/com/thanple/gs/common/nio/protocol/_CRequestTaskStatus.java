// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CRequestTaskStatus.proto

package com.thanple.gs.common.nio.protocol;

public final class _CRequestTaskStatus {
  private _CRequestTaskStatus() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface CRequestTaskStatusOrBuilder extends
      // @@protoc_insertion_point(interface_extends:CRequestTaskStatus)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>required int32 type = 1;</code>
     */
    boolean hasType();
    /**
     * <code>required int32 type = 1;</code>
     */
    int getType();
  }
  /**
   * Protobuf type {@code CRequestTaskStatus}
   */
  public static final class CRequestTaskStatus extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:CRequestTaskStatus)
      CRequestTaskStatusOrBuilder {
    // Use CRequestTaskStatus.newBuilder() to construct.
    private CRequestTaskStatus(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private CRequestTaskStatus(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final CRequestTaskStatus defaultInstance;
    public static CRequestTaskStatus getDefaultInstance() {
      return defaultInstance;
    }

    public CRequestTaskStatus getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private CRequestTaskStatus(
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
              type_ = input.readInt32();
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
      return com.thanple.gs.common.nio.protocol._CRequestTaskStatus.internal_static_CRequestTaskStatus_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.thanple.gs.common.nio.protocol._CRequestTaskStatus.internal_static_CRequestTaskStatus_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.class, com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.Builder.class);
    }

    public static com.google.protobuf.Parser<CRequestTaskStatus> PARSER =
        new com.google.protobuf.AbstractParser<CRequestTaskStatus>() {
      public CRequestTaskStatus parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new CRequestTaskStatus(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<CRequestTaskStatus> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int TYPE_FIELD_NUMBER = 1;
    private int type_;
    /**
     * <code>required int32 type = 1;</code>
     */
    public boolean hasType() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>required int32 type = 1;</code>
     */
    public int getType() {
      return type_;
    }

    private void initFields() {
      type_ = 0;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasType()) {
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
        output.writeInt32(1, type_);
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
          .computeInt32Size(1, type_);
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

    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus prototype) {
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
     * Protobuf type {@code CRequestTaskStatus}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:CRequestTaskStatus)
        com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatusOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.thanple.gs.common.nio.protocol._CRequestTaskStatus.internal_static_CRequestTaskStatus_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.thanple.gs.common.nio.protocol._CRequestTaskStatus.internal_static_CRequestTaskStatus_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.class, com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.Builder.class);
      }

      // Construct using com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.newBuilder()
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
        type_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.thanple.gs.common.nio.protocol._CRequestTaskStatus.internal_static_CRequestTaskStatus_descriptor;
      }

      public com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus getDefaultInstanceForType() {
        return com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.getDefaultInstance();
      }

      public com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus build() {
        com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus buildPartial() {
        com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus result = new com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.type_ = type_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus) {
          return mergeFrom((com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus other) {
        if (other == com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus.getDefaultInstance()) return this;
        if (other.hasType()) {
          setType(other.getType());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        if (!hasType()) {
          
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int type_ ;
      /**
       * <code>required int32 type = 1;</code>
       */
      public boolean hasType() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>required int32 type = 1;</code>
       */
      public int getType() {
        return type_;
      }
      /**
       * <code>required int32 type = 1;</code>
       */
      public Builder setType(int value) {
        bitField0_ |= 0x00000001;
        type_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 type = 1;</code>
       */
      public Builder clearType() {
        bitField0_ = (bitField0_ & ~0x00000001);
        type_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:CRequestTaskStatus)
    }

    static {
      defaultInstance = new CRequestTaskStatus(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:CRequestTaskStatus)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_CRequestTaskStatus_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_CRequestTaskStatus_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\030CRequestTaskStatus.proto\"\"\n\022CRequestTa" +
      "skStatus\022\014\n\004type\030\001 \002(\005B9\n\"com.thanple.gs" +
      ".common.nio.protocolB\023_CRequestTaskStatu" +
      "s"
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
    internal_static_CRequestTaskStatus_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_CRequestTaskStatus_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_CRequestTaskStatus_descriptor,
        new java.lang.String[] { "Type", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
