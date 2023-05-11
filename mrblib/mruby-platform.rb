module Platform
  def self.windows?
    [:windows_64, :windows_32].include?(get_platform)
  end

  def self.mac?
    get_platform == :macos
  end

  def self.ios?
    get_platform == :ios
  end

  def self.apple?
    [:macos, :ios, :apple].include?(get_platform)
  end

  def self.web?
    get_platform == :web
  end

  def self.android?
    get_platform == :android
  end

  def self.mobile?
    ios? || android?
  end

  def self.linux?
    get_platform == :linux
  end

  def self.unix?
    get_platform == :unix
  end

  def self.posix?
    get_platform == :posix
  end

  def self.unknown?
    get_platform == :unknown
  end
end

class PlatformError < StandardError
end
