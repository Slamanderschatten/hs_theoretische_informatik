//1
start s
end e

s 0 _ _ -> s _ 0 _ R R N
s 1 _ _ -> s _ 1 _ R R N
s _ _ _ -> n _ 0 _ R R N

n 0 _ _ -> n _ _ 0 R N R
n 1 _ _ -> n _ _ 1 R N R
n _ _ _ -> a _ _ _ N L L

a _ _ _ -> e _ _ _ R N N
a _ 0 0 -> a 0 _ _ L L L
a _ 0 1 -> a 1 _ _ L L L
a _ _ 1 -> a 1 _ _ L L L
a _ 1 0 -> a 1 _ _ L L L
a _ 1 _ -> a 1 _ _ L L L
a _ 1 1 -> c 0 _ _ L L L


c _ _ _ -> a 1 _ _ L N N
c _ 0 0 -> a 1 _ _ L L L
c _ 0 1 -> c 0 _ _ L L L
c _ _ 1 -> c 0 _ _ L L L
c _ 1 0 -> c 0 _ _ L L L
c _ 1 _ -> c 0 _ _ L L L
c _ 1 1 -> c 1 _ _ L L L
