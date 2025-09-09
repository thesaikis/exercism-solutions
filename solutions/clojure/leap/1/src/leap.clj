(ns leap)

(defn leap-year? [year] ;; <- argslist goes here
  (or (= (mod year 400) 0) (and (= (mod year 4) 0) (not= (mod year 100) 0)))
)
