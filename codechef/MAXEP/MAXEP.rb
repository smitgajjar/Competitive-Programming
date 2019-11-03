n = gets.chomp.to_i
c = gets.chomp.to_i
low=1, high=n, mid=n
while (low < high)
	puts "1 #{mid}"
	puts "\n"
	value=gets.to_i
	if value==0
		low=(mid+1).to_i;
	else
		puts "2\n"
		high=mid.to_i
	end
	mid=((low+high)/2).to_i
end

puts "3 #{mid}\n"

