void alternatingSplitList(struct Node *head)
{
    Node *aTail;
    Node *bTail;

    int pos = 1;

    Node *curr = head;
    while (curr != NULL)
    {
        if (pos % 2 == 1)
        {
            if (a == NULL)
            {
                a = aTail = curr;
            }
            else
            {
                aTail->next = curr;
                aTail = curr;
            }
        }
        else
        {
            if (b == NULL)
            {
                b = bTail = curr;
            }
            else
            {
                bTail->next = curr;
                bTail = curr;
            }
        }

        pos++;
        curr = curr->next;
    }

    if (a != NULL)
    {
        aTail->next = NULL;
    }
    if (b != NULL)
    {
        bTail->next = NULL;
    }
}