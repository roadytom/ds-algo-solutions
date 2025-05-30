package designpatterns.behavioralpatterns.strategy.structure;

import designpatterns.behavioralpatterns.strategy.structure.concretestrategies.ConcreteStrategyAdd;

/**
 * Client code picks a concrete strategy and passes it to the context.
 * The client should be aware of the differences between strategies
 * in order to make the right choice.
 */
public class ClientApplication {
  public static void main(String[] args) {
    Context context = new Context();
    // depending on use case we should choose strategy
    context.setStrategy(new ConcreteStrategyAdd());
  }
}
