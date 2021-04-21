DoublyLinkedListNode *reverse(DoublyLinkedListNode *head)
{
    DoublyLinkedListNode *temp = head, *left, *newhead = head;
    while (temp != NULL)
    {
        left = temp->prev;
        temp->prev = temp->next;
        temp->next = left;
        newhead = temp;
        temp = temp->prev;
    }
    return newhead;
}