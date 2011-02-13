#!/usr/local/bin/ruby
require 'webrick'
    include WEBrick

s = HTTPServer.new(:Port => 2000, :DocumentRoot => Dir::pwd)

# mount subdirectories
s.mount("/cgi-bin",HTTPServlet::FileHandler, Dir.pwd+"/cgi-bin")
s.mount("/include",HTTPServlet::FileHandler, Dir.pwd+"/include")

trap("INT"){ s.shutdown }
s.start
