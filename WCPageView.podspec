Pod::Spec.new do |s|
  s.name         = 'WCPageView'
  s.version      = '0.0.1'
  s.summary      = "A easy way to implementation PageView"
  s.author       = { "王策" => "634692517@qq.com" }
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.homepage     = "https://github.com/HaloWang/WCPageView"
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/HaloWang/WCPageView.git", :tag => "0.0.1" }
  s.source_files = "WCPageView/*.{h,m}"
  s.framework    = "UIKit"
  s.requires_arc = true
end
