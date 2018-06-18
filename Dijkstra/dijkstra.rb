require 'pqueue'
# require 'pry'

class Dijkstra
  class Node
    attr_accessor :cost, :checked, :from, :id
    def initialize(id)
      @cost = Float::INFINITY
      @checked = false
      @from = nil
      @id   = id
    end

    def checked?
      checked
    end

    def check
      self.checked = true
    end

    # 新しいコストが小さければ上書き
    def update_cost_to(new_cost)
      self.cost = new_cost
    end

    # I'm from (nodes id)
    def im_from(from)
      self.from = from
    end

    def update_cost_with_from(new_cost, from)
      return unless cost > new_cost
      update_cost_to(new_cost)
      im_from(from)
    end

    def start?
      from.nil?
    end
  end

  attr_accessor :start, :goal, :nodes, :costs
  def initialize
    @start    = nil
    @goal     = nil
    @nodes    = []
    @costs    = []
  end

  def make_input
    n, r = gets.chomp!.split.map(&:to_i)

    self.costs = Array.new(n) { Array.new(n, nil) }
    r.times do
      f, t, c = gets.chomp!.split.map(&:to_i)
      costs[f][t] = c
    end

    self.start, self.goal = gets.chomp!.split.map(&:to_i)

    n.times do |i|
      nodes << Dijkstra::Node.new(i)
    end
  end

  def solve
    unchecks = PQueue.new { |a, b| a.cost < b.cost }

    # start node
    nodes[start].update_cost_to(0)
    unchecks.push(nodes[start])

    loop do
      return if unchecks.empty?
      current = unchecks.pop
      return current if current.id == goal
      current.check
      costs[current.id].each_with_index do |cost, i|
        next if cost.nil?
        new_cost = current.cost + cost
        nodes[i].update_cost_with_from(new_cost, current.id)
        unchecks.push(nodes[i])
      end
    end
  end

  def trace_routes(node)
    return trace_routes(nodes[node.from]) + " #{node.id}" unless node.from.nil?
    node.id.to_s
  end
end

Dijkstra.new.tap do |d|
  d.make_input
  puts d.trace_routes(d.solve)
end
