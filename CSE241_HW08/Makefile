JCC = javac

JFLAGS =


default: Bigram.class BigramDyn.class BigramMap.class Pair.class _mainTester.class

Bigram.class: Bigram.java
	$(JCC) $(JFLAGS) Bigram.java

BigramDyn.class: BigramDyn.java
	$(JCC) $(JFLAGS) BigramDyn.java

BigramMap.class: BigramMap.java
	$(JCC) $(JFLAGS) BigramMap.java

Pair.class: Pair.java
	$(JCC) $(JFLAGS) Pair.java

_mainTester.class: _mainTester.java
	$(JCC) $(JFLAGS) _mainTester.java

clean: 
	$(RM) *.class
