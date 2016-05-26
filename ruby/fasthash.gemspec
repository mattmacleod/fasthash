lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'fasthash/version'

Gem::Specification.new do |spec|
  spec.name          = "fasthash"
  spec.version       = Fasthash::VERSION
  spec.authors       = ["Matthew MacLeod"]
  spec.email         = ["matt@umm.io"]
  spec.summary       = %q{fasthash}
  spec.description   = %q{fasthash}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.platform = Gem::Platform::CURRENT

  spec.add_development_dependency "bundler", "~> 1.6"
  spec.add_development_dependency "rake"

  spec.extensions << "ext/fasthash/extconf.rb"
end
