//�V�[���Ǘ��p�w�b�_
#pragma once

class CManager;//�V�[���Ǘ��N���X

//�V�[���̊��N���X
class CScene {
protected:
	CManager* manager{ nullptr };
public:
	CScene(CManager* pManager) { manager = pManager; };

	//�X�V����
	virtual int Update() { return 0; };
	//�`�揈��
	virtual void Draw() {};
	//�f�X�g���N�^
	virtual ~CScene() {};
};

//�V�[���Ǘ��N���X
class CManager {
public:
	//�V�[���|�C���^
	CScene* scene{ nullptr };

	CManager() {};
	int Update() { scene->Update(); return 0; };
	void Draw() { scene->Draw(); };

	//�V�[���̍폜
	void Scene_Delete() {
		scene->~CScene();
	}

	~CManager() { delete scene; };
};

