#!/usr/local/bin/ruby
require 'webrick'
    include WEBrick

s = HTTPServer.new(
	:Port => 2007, 
	:DocumentRoot => Dir::pwd
)

# mount subdirectories

s.mount("/include",HTTPServlet::FileHandler, Dir.pwd+"/include")
s.mount("/cgi-bin",HTTPServlet::FileHandler, Dir.pwd+"/cgi-bin")

trap("INT"){ s.shutdown }
s.start
