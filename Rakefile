task :default => :build
task :build => %w[compiler]

rule ".beam" => ".erl" do |t|
  sh "erlc +nowarn_unused_vars -o #{File.dirname(t.name)} #{t.source}"
end

task :compiler => %w[src/reia/compiler/scanner.erl]

file "src/leex/leex.beam" => "src/leex/leex.erl"
file "src/reia/compiler/scanner.erl" => %w[src/reia/compiler/scanner.xrl src/leex/leex.beam] do
  sh "erl -eval 'leex:file(\"src/reia/compiler/scanner.xrl\")' -pa src/leex -noshell -s init stop"
end

task :clean do
  rm_f 'src/leex/leex.beam'
  rm_f 'src/reia/compiler/scanner.erl'
  rm_rf 'ebin'
end
