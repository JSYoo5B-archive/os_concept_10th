//
//  main.swift
//  MoteCarlo
//
//  Created by HyeJee Kim on 2022/08/21.
//

import Foundation

func checkInclusion(x: Double, y: Double) -> Bool {
    return (x * x) + (y * y) <= 1
}

let max: Int = Int.max

var x: Double
var y: Double

var count: Double = 0
var inclusionCount: Double = 0

while true {
    for _ in 1...1_000_000 {
        x = Double(Int.random(in: 1...max)) / Double(max)
        y = Double(Int.random(in: 1...max)) / Double(max)
        
        count += 1
        
        if checkInclusion(x: x, y: y) {
            inclusionCount += 1
        }
    }
    
    print("\(count), \(inclusionCount): \(inclusionCount / count * 4.0)")
}