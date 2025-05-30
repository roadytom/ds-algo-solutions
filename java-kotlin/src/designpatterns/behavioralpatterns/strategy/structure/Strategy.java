package designpatterns.behavioralpatterns.strategy.structure;

/**
 * The strategy interface declares operations common to all
 * supported versions of some algorithm. The context uses this
 * interface to call algorithm defined by concrete
 * strategies
 */
public interface Strategy {
  int execute(int a, int b);
}
