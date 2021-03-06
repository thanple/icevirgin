// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CBuy.proto

package com.thanple.gs.common.nio.protocol;

public final class _CBuy {
  private _CBuy() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface CBuyOrBuilder extends
      // @@protoc_insertion_point(interface_extends:CBuy)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>required int32 shop = 1;</code>
     */
    boolean hasShop();
    /**
     * <code>required int32 shop = 1;</code>
     */
    int getShop();
  }
  /**
   * Protobuf type {@code CBuy}
   */
  public static final class CBuy extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:CBuy)
      CBuyOrBuilder {
    // Use CBuy.newBuilder() to construct.
    private CBuy(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private CBuy(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final CBuy defaultInstance;
    public static CBuy getDefaultInstance() {
      return defaultInstance;
    }

    public CBuy getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private CBuy(
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
              shop_ = input.readInt32();
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
      return com.thanple.gs.common.nio.protocol._CBuy.internal_static_CBuy_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.thanple.gs.common.nio.protocol._CBuy.internal_static_CBuy_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.thanple.gs.common.nio.protocol._CBuy.CBuy.class, com.thanple.gs.common.nio.protocol._CBuy.CBuy.Builder.class);
    }

    public static com.google.protobuf.Parser<CBuy> PARSER =
        new com.google.protobuf.AbstractParser<CBuy>() {
      public CBuy parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new CBuy(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<CBuy> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int SHOP_FIELD_NUMBER = 1;
    private int shop_;
    /**
     * <code>required int32 shop = 1;</code>
     */
    public boolean hasShop() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>required int32 shop = 1;</code>
     */
    public int getShop() {
      return shop_;
    }

    private void initFields() {
      shop_ = 0;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasShop()) {
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
        output.writeInt32(1, shop_);
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
          .computeInt32Size(1, shop_);
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

    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CBuy.CBuy parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.thanple.gs.common.nio.protocol._CBuy.CBuy prototype) {
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
     * Protobuf type {@code CBuy}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:CBuy)
        com.thanple.gs.common.nio.protocol._CBuy.CBuyOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.thanple.gs.common.nio.protocol._CBuy.internal_static_CBuy_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.thanple.gs.common.nio.protocol._CBuy.internal_static_CBuy_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.thanple.gs.common.nio.protocol._CBuy.CBuy.class, com.thanple.gs.common.nio.protocol._CBuy.CBuy.Builder.class);
      }

      // Construct using com.thanple.gs.common.nio.protocol._CBuy.CBuy.newBuilder()
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
        shop_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.thanple.gs.common.nio.protocol._CBuy.internal_static_CBuy_descriptor;
      }

      public com.thanple.gs.common.nio.protocol._CBuy.CBuy getDefaultInstanceForType() {
        return com.thanple.gs.common.nio.protocol._CBuy.CBuy.getDefaultInstance();
      }

      public com.thanple.gs.common.nio.protocol._CBuy.CBuy build() {
        com.thanple.gs.common.nio.protocol._CBuy.CBuy result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.thanple.gs.common.nio.protocol._CBuy.CBuy buildPartial() {
        com.thanple.gs.common.nio.protocol._CBuy.CBuy result = new com.thanple.gs.common.nio.protocol._CBuy.CBuy(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.shop_ = shop_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.thanple.gs.common.nio.protocol._CBuy.CBuy) {
          return mergeFrom((com.thanple.gs.common.nio.protocol._CBuy.CBuy)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.thanple.gs.common.nio.protocol._CBuy.CBuy other) {
        if (other == com.thanple.gs.common.nio.protocol._CBuy.CBuy.getDefaultInstance()) return this;
        if (other.hasShop()) {
          setShop(other.getShop());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        if (!hasShop()) {
          
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.thanple.gs.common.nio.protocol._CBuy.CBuy parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.thanple.gs.common.nio.protocol._CBuy.CBuy) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int shop_ ;
      /**
       * <code>required int32 shop = 1;</code>
       */
      public boolean hasShop() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>required int32 shop = 1;</code>
       */
      public int getShop() {
        return shop_;
      }
      /**
       * <code>required int32 shop = 1;</code>
       */
      public Builder setShop(int value) {
        bitField0_ |= 0x00000001;
        shop_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 shop = 1;</code>
       */
      public Builder clearShop() {
        bitField0_ = (bitField0_ & ~0x00000001);
        shop_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:CBuy)
    }

    static {
      defaultInstance = new CBuy(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:CBuy)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_CBuy_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_CBuy_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\nCBuy.proto\"\024\n\004CBuy\022\014\n\004shop\030\001 \002(\005B+\n\"co" +
      "m.thanple.gs.common.nio.protocolB\005_CBuy"
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
    internal_static_CBuy_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_CBuy_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_CBuy_descriptor,
        new java.lang.String[] { "Shop", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
