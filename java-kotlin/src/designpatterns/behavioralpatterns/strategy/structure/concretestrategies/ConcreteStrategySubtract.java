package designpatterns.behavioralpatterns.strategy.structure.concretestrategies;

import designpatterns.behavioralpatterns.strategy.structure.Strategy;

public class ConcreteStrategySubtract implements Strategy {
  @Override
  public int execute(int a, int b) {
    return a - b;
  }
}
