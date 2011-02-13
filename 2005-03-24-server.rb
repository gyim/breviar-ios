#!/usr/local/bin/ruby
require 'webrick'
    include WEBrick

CGIRunner = "\"#{Ruby}\" \"#{Config::LIBDIR}/httpservlet/cgi_runner.rb\""

# http://www.talkaboutprogramming.com/group/comp.lang.ruby/messages/78404.html

s = HTTPServer.new(
	:Port => 2000, 
	:DocumentRoot => Dir::pwd, 
	:CGIInterpreter => "\"#{WEBrick::HTTPServlet::CGIHandler::Ruby}\""
)

# mount subdirectories

s.mount("/include",HTTPServlet::FileHandler, Dir.pwd+"/include")
# s.mount("/cgi-bin",HTTPServlet::FileHandler, Dir.pwd+"/cgi-bin")
s.mount("/cgi-bin", HTTPServlet::CGIHandler, Dir.pwd+"/cgi-bin")
s.mount("/cgi-bin/uncgi.cgi",HTTPServlet::CGIHandler, Dir.pwd+"/cgi-bin/uncgi.cgi")

trap("INT"){ s.shutdown }
s.start
