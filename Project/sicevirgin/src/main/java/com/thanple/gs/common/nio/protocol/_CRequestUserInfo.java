// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CRequestUserInfo.proto

package com.thanple.gs.common.nio.protocol;

public final class _CRequestUserInfo {
  private _CRequestUserInfo() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface CRequestUserInfoOrBuilder extends
      // @@protoc_insertion_point(interface_extends:CRequestUserInfo)
      com.google.protobuf.MessageOrBuilder {
  }
  /**
   * Protobuf type {@code CRequestUserInfo}
   */
  public static final class CRequestUserInfo extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:CRequestUserInfo)
      CRequestUserInfoOrBuilder {
    // Use CRequestUserInfo.newBuilder() to construct.
    private CRequestUserInfo(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private CRequestUserInfo(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final CRequestUserInfo defaultInstance;
    public static CRequestUserInfo getDefaultInstance() {
      return defaultInstance;
    }

    public CRequestUserInfo getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private CRequestUserInfo(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      initFields();
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
      return com.thanple.gs.common.nio.protocol._CRequestUserInfo.internal_static_CRequestUserInfo_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.thanple.gs.common.nio.protocol._CRequestUserInfo.internal_static_CRequestUserInfo_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.class, com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.Builder.class);
    }

    public static com.google.protobuf.Parser<CRequestUserInfo> PARSER =
        new com.google.protobuf.AbstractParser<CRequestUserInfo>() {
      public CRequestUserInfo parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new CRequestUserInfo(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<CRequestUserInfo> getParserForType() {
      return PARSER;
    }

    private void initFields() {
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      getUnknownFields().writeTo(output);
    }

    private int memoizedSerializedSize = -1;
    public int getSerializedSize() {
      int size = memoizedSerializedSize;
      if (size != -1) return size;

      size = 0;
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

    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo prototype) {
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
     * Protobuf type {@code CRequestUserInfo}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:CRequestUserInfo)
        com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfoOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.thanple.gs.common.nio.protocol._CRequestUserInfo.internal_static_CRequestUserInfo_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.thanple.gs.common.nio.protocol._CRequestUserInfo.internal_static_CRequestUserInfo_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.class, com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.Builder.class);
      }

      // Construct using com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.newBuilder()
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
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.thanple.gs.common.nio.protocol._CRequestUserInfo.internal_static_CRequestUserInfo_descriptor;
      }

      public com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo getDefaultInstanceForType() {
        return com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.getDefaultInstance();
      }

      public com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo build() {
        com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo buildPartial() {
        com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo result = new com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo(this);
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo) {
          return mergeFrom((com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo other) {
        if (other == com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo.getDefaultInstance()) return this;
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }

      // @@protoc_insertion_point(builder_scope:CRequestUserInfo)
    }

    static {
      defaultInstance = new CRequestUserInfo(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:CRequestUserInfo)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_CRequestUserInfo_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_CRequestUserInfo_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\026CRequestUserInfo.proto\"\022\n\020CRequestUser" +
      "InfoB7\n\"com.thanple.gs.common.nio.protoc" +
      "olB\021_CRequestUserInfo"
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
    internal_static_CRequestUserInfo_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_CRequestUserInfo_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_CRequestUserInfo_descriptor,
        new java.lang.String[] { });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
