def randWeight(weights)
  value = (0.0..weights.sum)
  acumr = 0
  weights.each_with_index do |w, i|
    acumr += w
    return i if v <= acumr
  end
end
