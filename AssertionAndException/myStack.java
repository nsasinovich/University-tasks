import java.util.logging.Logger;

public class myStack {

    public myStack() {
        topOfStack = null;
    }

    public boolean isEmpty() {
        return topOfStack == null;
    }

    public void clear() {
        topOfStack = null;
    }

    public void push(Object x) {
        assert (x!=null):"Stored object is NULL";
        topOfStack = new Node(x, topOfStack);
    }

    public void pop() throws myException {

        if (isEmpty())
            emptyStackError("Trying to pop fromEmptyStack");
        topOfStack = topOfStack.next;
    }

    public Object top() throws myException {

        if (isEmpty())
            emptyStackError("Trying to get top element fromEmptyStack");
            return topOfStack.element;
    }

    private Node topOfStack;
    private static Logger log=Logger.getLogger(myStack.class.getName());

    private void emptyStackError(String msg) throws myException {
        myException emptyStack=new myException("Error!Stack is empty!");
        log.throwing(myStack.class.getName(),msg,emptyStack);
        throw emptyStack;
    }
}
class Node {

    public Node(Object newElement, Node newNext) {
        element = newElement;
        next = newNext;
    }

    public Object element;
    public Node next;
}
