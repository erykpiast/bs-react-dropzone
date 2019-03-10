module Function = struct
  let unary (fn: 'a) : 'a = [%raw "(a) => fn(a)" ];;
  let (||>) f g x = g(f(x));;
end
