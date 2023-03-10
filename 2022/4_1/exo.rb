def main
  nb_recur = 0
  $stdin.read.split("\n").each do |l|
    l.gsub!("\n", '')
    nb_recur += 1 if check_line l
  end
  puts nb_recur
end

def check_line(line)
  loop_nb = 0
  arr2 = []

  arr = line.split(',', 2)
  arr.each do |x|
    arr2.push(x.split('-', 2))
    if (loop_nb == 1)
      loop_nb = 0
      if (arr2[0][0].to_i <= arr2[1][0].to_i && arr2[0][1].to_i >= arr2[1][1].to_i)
        arr2 = []
        return true 
      end
      if (arr2[0][0].to_i >= arr2[1][0].to_i && arr2[0][1].to_i <= arr2[1][1].to_i)
        arr2 = []
        return true 
      end
    end
    loop_nb += 1
  end
  false
end
main
