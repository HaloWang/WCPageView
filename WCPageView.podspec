Pod::Spec.new do |s|
  s.name         = 'WCPageView'
  s.version      = '0.0.3'
  s.summary      = "A easy way to implementation PageView"
  s.author       = { "王策" => "634692517@qq.com" }
  s.homepage     = "https://github.com/HaloWang/WCPageView"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.platform     = :ios, "7.0"
  s.source       = { 
    :git => "https://github.com/HaloWang/WCPageView.git", 
    :tag => s.version 
  }
  s.source_files = "WCPageView/*.{h,m}"
  s.framework    = "UIKit"
  s.requires_arc = true
end
