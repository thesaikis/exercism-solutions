=begin
Write your code for the 'Raindrops' exercise in this file. Make the tests in
`raindrops_test.rb` pass.

To get started with TDD, see the `README.md` file in your
`ruby/raindrops` directory.
=end

class Raindrops
  def self.convert(num)
    res = ""

    if num % 3 == 0
      res << "Pling"
    end

    if num % 5 == 0
      res << "Plang"
    end

    if num % 7 == 0
      res << "Plong"
    end

    if res == ""
      res << num.to_s
    end
    
    return res
  end
end