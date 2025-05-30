package designpatterns.behavioralpatterns.strategy.structure;

public class Context {
  private Strategy strategy;

  public Strategy getStrategy() {
    return strategy;
  }

  public void setStrategy(Strategy strategy) {
    this.strategy = strategy;
  }

  public int executeStrategy(int a, int b) {
    return strategy.execute(a, b);
  }
}
