// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CCreateRole.proto

package com.thanple.gs.common.nio.protocol;

public final class _CCreateRole {
  private _CCreateRole() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface CCreateRoleOrBuilder extends
      // @@protoc_insertion_point(interface_extends:CCreateRole)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>required string name = 1;</code>
     */
    boolean hasName();
    /**
     * <code>required string name = 1;</code>
     */
    java.lang.String getName();
    /**
     * <code>required string name = 1;</code>
     */
    com.google.protobuf.ByteString
        getNameBytes();

    /**
     * <code>required string password = 2;</code>
     */
    boolean hasPassword();
    /**
     * <code>required string password = 2;</code>
     */
    java.lang.String getPassword();
    /**
     * <code>required string password = 2;</code>
     */
    com.google.protobuf.ByteString
        getPasswordBytes();

    /**
     * <code>required string number = 3;</code>
     */
    boolean hasNumber();
    /**
     * <code>required string number = 3;</code>
     */
    java.lang.String getNumber();
    /**
     * <code>required string number = 3;</code>
     */
    com.google.protobuf.ByteString
        getNumberBytes();

    /**
     * <code>required int32 hair = 4;</code>
     */
    boolean hasHair();
    /**
     * <code>required int32 hair = 4;</code>
     */
    int getHair();

    /**
     * <code>required int32 body = 5;</code>
     */
    boolean hasBody();
    /**
     * <code>required int32 body = 5;</code>
     */
    int getBody();

    /**
     * <code>required int32 weapon = 6;</code>
     */
    boolean hasWeapon();
    /**
     * <code>required int32 weapon = 6;</code>
     */
    int getWeapon();
  }
  /**
   * Protobuf type {@code CCreateRole}
   */
  public static final class CCreateRole extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:CCreateRole)
      CCreateRoleOrBuilder {
    // Use CCreateRole.newBuilder() to construct.
    private CCreateRole(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private CCreateRole(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final CCreateRole defaultInstance;
    public static CCreateRole getDefaultInstance() {
      return defaultInstance;
    }

    public CCreateRole getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private CCreateRole(
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
            case 10: {
              com.google.protobuf.ByteString bs = input.readBytes();
              bitField0_ |= 0x00000001;
              name_ = bs;
              break;
            }
            case 18: {
              com.google.protobuf.ByteString bs = input.readBytes();
              bitField0_ |= 0x00000002;
              password_ = bs;
              break;
            }
            case 26: {
              com.google.protobuf.ByteString bs = input.readBytes();
              bitField0_ |= 0x00000004;
              number_ = bs;
              break;
            }
            case 32: {
              bitField0_ |= 0x00000008;
              hair_ = input.readInt32();
              break;
            }
            case 40: {
              bitField0_ |= 0x00000010;
              body_ = input.readInt32();
              break;
            }
            case 48: {
              bitField0_ |= 0x00000020;
              weapon_ = input.readInt32();
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
      return com.thanple.gs.common.nio.protocol._CCreateRole.internal_static_CCreateRole_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.thanple.gs.common.nio.protocol._CCreateRole.internal_static_CCreateRole_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.class, com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.Builder.class);
    }

    public static com.google.protobuf.Parser<CCreateRole> PARSER =
        new com.google.protobuf.AbstractParser<CCreateRole>() {
      public CCreateRole parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new CCreateRole(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<CCreateRole> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int NAME_FIELD_NUMBER = 1;
    private java.lang.Object name_;
    /**
     * <code>required string name = 1;</code>
     */
    public boolean hasName() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>required string name = 1;</code>
     */
    public java.lang.String getName() {
      java.lang.Object ref = name_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          name_ = s;
        }
        return s;
      }
    }
    /**
     * <code>required string name = 1;</code>
     */
    public com.google.protobuf.ByteString
        getNameBytes() {
      java.lang.Object ref = name_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        name_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    public static final int PASSWORD_FIELD_NUMBER = 2;
    private java.lang.Object password_;
    /**
     * <code>required string password = 2;</code>
     */
    public boolean hasPassword() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <code>required string password = 2;</code>
     */
    public java.lang.String getPassword() {
      java.lang.Object ref = password_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          password_ = s;
        }
        return s;
      }
    }
    /**
     * <code>required string password = 2;</code>
     */
    public com.google.protobuf.ByteString
        getPasswordBytes() {
      java.lang.Object ref = password_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        password_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    public static final int NUMBER_FIELD_NUMBER = 3;
    private java.lang.Object number_;
    /**
     * <code>required string number = 3;</code>
     */
    public boolean hasNumber() {
      return ((bitField0_ & 0x00000004) == 0x00000004);
    }
    /**
     * <code>required string number = 3;</code>
     */
    public java.lang.String getNumber() {
      java.lang.Object ref = number_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          number_ = s;
        }
        return s;
      }
    }
    /**
     * <code>required string number = 3;</code>
     */
    public com.google.protobuf.ByteString
        getNumberBytes() {
      java.lang.Object ref = number_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        number_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    public static final int HAIR_FIELD_NUMBER = 4;
    private int hair_;
    /**
     * <code>required int32 hair = 4;</code>
     */
    public boolean hasHair() {
      return ((bitField0_ & 0x00000008) == 0x00000008);
    }
    /**
     * <code>required int32 hair = 4;</code>
     */
    public int getHair() {
      return hair_;
    }

    public static final int BODY_FIELD_NUMBER = 5;
    private int body_;
    /**
     * <code>required int32 body = 5;</code>
     */
    public boolean hasBody() {
      return ((bitField0_ & 0x00000010) == 0x00000010);
    }
    /**
     * <code>required int32 body = 5;</code>
     */
    public int getBody() {
      return body_;
    }

    public static final int WEAPON_FIELD_NUMBER = 6;
    private int weapon_;
    /**
     * <code>required int32 weapon = 6;</code>
     */
    public boolean hasWeapon() {
      return ((bitField0_ & 0x00000020) == 0x00000020);
    }
    /**
     * <code>required int32 weapon = 6;</code>
     */
    public int getWeapon() {
      return weapon_;
    }

    private void initFields() {
      name_ = "";
      password_ = "";
      number_ = "";
      hair_ = 0;
      body_ = 0;
      weapon_ = 0;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasName()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasPassword()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasNumber()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasHair()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasBody()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasWeapon()) {
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
        output.writeBytes(1, getNameBytes());
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeBytes(2, getPasswordBytes());
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        output.writeBytes(3, getNumberBytes());
      }
      if (((bitField0_ & 0x00000008) == 0x00000008)) {
        output.writeInt32(4, hair_);
      }
      if (((bitField0_ & 0x00000010) == 0x00000010)) {
        output.writeInt32(5, body_);
      }
      if (((bitField0_ & 0x00000020) == 0x00000020)) {
        output.writeInt32(6, weapon_);
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
          .computeBytesSize(1, getNameBytes());
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeBytesSize(2, getPasswordBytes());
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        size += com.google.protobuf.CodedOutputStream
          .computeBytesSize(3, getNumberBytes());
      }
      if (((bitField0_ & 0x00000008) == 0x00000008)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(4, hair_);
      }
      if (((bitField0_ & 0x00000010) == 0x00000010)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(5, body_);
      }
      if (((bitField0_ & 0x00000020) == 0x00000020)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(6, weapon_);
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

    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole prototype) {
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
     * Protobuf type {@code CCreateRole}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:CCreateRole)
        com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRoleOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.thanple.gs.common.nio.protocol._CCreateRole.internal_static_CCreateRole_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.thanple.gs.common.nio.protocol._CCreateRole.internal_static_CCreateRole_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.class, com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.Builder.class);
      }

      // Construct using com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.newBuilder()
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
        name_ = "";
        bitField0_ = (bitField0_ & ~0x00000001);
        password_ = "";
        bitField0_ = (bitField0_ & ~0x00000002);
        number_ = "";
        bitField0_ = (bitField0_ & ~0x00000004);
        hair_ = 0;
        bitField0_ = (bitField0_ & ~0x00000008);
        body_ = 0;
        bitField0_ = (bitField0_ & ~0x00000010);
        weapon_ = 0;
        bitField0_ = (bitField0_ & ~0x00000020);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.thanple.gs.common.nio.protocol._CCreateRole.internal_static_CCreateRole_descriptor;
      }

      public com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole getDefaultInstanceForType() {
        return com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.getDefaultInstance();
      }

      public com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole build() {
        com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole buildPartial() {
        com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole result = new com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.name_ = name_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.password_ = password_;
        if (((from_bitField0_ & 0x00000004) == 0x00000004)) {
          to_bitField0_ |= 0x00000004;
        }
        result.number_ = number_;
        if (((from_bitField0_ & 0x00000008) == 0x00000008)) {
          to_bitField0_ |= 0x00000008;
        }
        result.hair_ = hair_;
        if (((from_bitField0_ & 0x00000010) == 0x00000010)) {
          to_bitField0_ |= 0x00000010;
        }
        result.body_ = body_;
        if (((from_bitField0_ & 0x00000020) == 0x00000020)) {
          to_bitField0_ |= 0x00000020;
        }
        result.weapon_ = weapon_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole) {
          return mergeFrom((com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole other) {
        if (other == com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole.getDefaultInstance()) return this;
        if (other.hasName()) {
          bitField0_ |= 0x00000001;
          name_ = other.name_;
          onChanged();
        }
        if (other.hasPassword()) {
          bitField0_ |= 0x00000002;
          password_ = other.password_;
          onChanged();
        }
        if (other.hasNumber()) {
          bitField0_ |= 0x00000004;
          number_ = other.number_;
          onChanged();
        }
        if (other.hasHair()) {
          setHair(other.getHair());
        }
        if (other.hasBody()) {
          setBody(other.getBody());
        }
        if (other.hasWeapon()) {
          setWeapon(other.getWeapon());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        if (!hasName()) {
          
          return false;
        }
        if (!hasPassword()) {
          
          return false;
        }
        if (!hasNumber()) {
          
          return false;
        }
        if (!hasHair()) {
          
          return false;
        }
        if (!hasBody()) {
          
          return false;
        }
        if (!hasWeapon()) {
          
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private java.lang.Object name_ = "";
      /**
       * <code>required string name = 1;</code>
       */
      public boolean hasName() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>required string name = 1;</code>
       */
      public java.lang.String getName() {
        java.lang.Object ref = name_;
        if (!(ref instanceof java.lang.String)) {
          com.google.protobuf.ByteString bs =
              (com.google.protobuf.ByteString) ref;
          java.lang.String s = bs.toStringUtf8();
          if (bs.isValidUtf8()) {
            name_ = s;
          }
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>required string name = 1;</code>
       */
      public com.google.protobuf.ByteString
          getNameBytes() {
        java.lang.Object ref = name_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          name_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>required string name = 1;</code>
       */
      public Builder setName(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000001;
        name_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required string name = 1;</code>
       */
      public Builder clearName() {
        bitField0_ = (bitField0_ & ~0x00000001);
        name_ = getDefaultInstance().getName();
        onChanged();
        return this;
      }
      /**
       * <code>required string name = 1;</code>
       */
      public Builder setNameBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000001;
        name_ = value;
        onChanged();
        return this;
      }

      private java.lang.Object password_ = "";
      /**
       * <code>required string password = 2;</code>
       */
      public boolean hasPassword() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <code>required string password = 2;</code>
       */
      public java.lang.String getPassword() {
        java.lang.Object ref = password_;
        if (!(ref instanceof java.lang.String)) {
          com.google.protobuf.ByteString bs =
              (com.google.protobuf.ByteString) ref;
          java.lang.String s = bs.toStringUtf8();
          if (bs.isValidUtf8()) {
            password_ = s;
          }
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>required string password = 2;</code>
       */
      public com.google.protobuf.ByteString
          getPasswordBytes() {
        java.lang.Object ref = password_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          password_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>required string password = 2;</code>
       */
      public Builder setPassword(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        password_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required string password = 2;</code>
       */
      public Builder clearPassword() {
        bitField0_ = (bitField0_ & ~0x00000002);
        password_ = getDefaultInstance().getPassword();
        onChanged();
        return this;
      }
      /**
       * <code>required string password = 2;</code>
       */
      public Builder setPasswordBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        password_ = value;
        onChanged();
        return this;
      }

      private java.lang.Object number_ = "";
      /**
       * <code>required string number = 3;</code>
       */
      public boolean hasNumber() {
        return ((bitField0_ & 0x00000004) == 0x00000004);
      }
      /**
       * <code>required string number = 3;</code>
       */
      public java.lang.String getNumber() {
        java.lang.Object ref = number_;
        if (!(ref instanceof java.lang.String)) {
          com.google.protobuf.ByteString bs =
              (com.google.protobuf.ByteString) ref;
          java.lang.String s = bs.toStringUtf8();
          if (bs.isValidUtf8()) {
            number_ = s;
          }
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>required string number = 3;</code>
       */
      public com.google.protobuf.ByteString
          getNumberBytes() {
        java.lang.Object ref = number_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          number_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>required string number = 3;</code>
       */
      public Builder setNumber(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000004;
        number_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required string number = 3;</code>
       */
      public Builder clearNumber() {
        bitField0_ = (bitField0_ & ~0x00000004);
        number_ = getDefaultInstance().getNumber();
        onChanged();
        return this;
      }
      /**
       * <code>required string number = 3;</code>
       */
      public Builder setNumberBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000004;
        number_ = value;
        onChanged();
        return this;
      }

      private int hair_ ;
      /**
       * <code>required int32 hair = 4;</code>
       */
      public boolean hasHair() {
        return ((bitField0_ & 0x00000008) == 0x00000008);
      }
      /**
       * <code>required int32 hair = 4;</code>
       */
      public int getHair() {
        return hair_;
      }
      /**
       * <code>required int32 hair = 4;</code>
       */
      public Builder setHair(int value) {
        bitField0_ |= 0x00000008;
        hair_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 hair = 4;</code>
       */
      public Builder clearHair() {
        bitField0_ = (bitField0_ & ~0x00000008);
        hair_ = 0;
        onChanged();
        return this;
      }

      private int body_ ;
      /**
       * <code>required int32 body = 5;</code>
       */
      public boolean hasBody() {
        return ((bitField0_ & 0x00000010) == 0x00000010);
      }
      /**
       * <code>required int32 body = 5;</code>
       */
      public int getBody() {
        return body_;
      }
      /**
       * <code>required int32 body = 5;</code>
       */
      public Builder setBody(int value) {
        bitField0_ |= 0x00000010;
        body_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 body = 5;</code>
       */
      public Builder clearBody() {
        bitField0_ = (bitField0_ & ~0x00000010);
        body_ = 0;
        onChanged();
        return this;
      }

      private int weapon_ ;
      /**
       * <code>required int32 weapon = 6;</code>
       */
      public boolean hasWeapon() {
        return ((bitField0_ & 0x00000020) == 0x00000020);
      }
      /**
       * <code>required int32 weapon = 6;</code>
       */
      public int getWeapon() {
        return weapon_;
      }
      /**
       * <code>required int32 weapon = 6;</code>
       */
      public Builder setWeapon(int value) {
        bitField0_ |= 0x00000020;
        weapon_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>required int32 weapon = 6;</code>
       */
      public Builder clearWeapon() {
        bitField0_ = (bitField0_ & ~0x00000020);
        weapon_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:CCreateRole)
    }

    static {
      defaultInstance = new CCreateRole(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:CCreateRole)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_CCreateRole_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_CCreateRole_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\021CCreateRole.proto\"i\n\013CCreateRole\022\014\n\004na" +
      "me\030\001 \002(\t\022\020\n\010password\030\002 \002(\t\022\016\n\006number\030\003 \002" +
      "(\t\022\014\n\004hair\030\004 \002(\005\022\014\n\004body\030\005 \002(\005\022\016\n\006weapon" +
      "\030\006 \002(\005B2\n\"com.thanple.gs.common.nio.prot" +
      "ocolB\014_CCreateRole"
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
    internal_static_CCreateRole_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_CCreateRole_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_CCreateRole_descriptor,
        new java.lang.String[] { "Name", "Password", "Number", "Hair", "Body", "Weapon", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
