#ifndef NODOC_H
#define NODOC_H

#define TEMPLATE_NODOC template <class KEY, class GIVEN>

TEMPLATE_NODOC
class NoDoc
{
private:
    KEY chave;
    GIVEN dado;
public:
    NoDoc(KEY,GIVEN);
    NoDoc(KEY);
    NoDoc();
    KEY getChave();
    GIVEN getDado();
    void setChave(KEY);
    void setDado(GIVEN);

};
#endif // NODOC_H
